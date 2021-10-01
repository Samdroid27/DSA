/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    map<TreeNode*,TreeNode*> parent;
    set<TreeNode*> visited;
    
    void getParent(TreeNode* root){
        if(!root) return;
        if(root->left){
            parent[root->left]= root;
            getParent(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            getParent(root->right);
        }
    }
    
    void dfs(TreeNode* root,int k){
        if(visited.find(root)!= visited.end()) return;
        visited.insert(root);
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(root->left) dfs(root->left,k-1);
        if(root->right) dfs(root->right,k-1);
        if(parent[root]) dfs(parent[root],k-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return ans;
        getParent(root);
        dfs(target,k);
        return ans;
    }
};
