// Preorder traversal of Binary Tree 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Iterative approach

// Implementation 1
vector<int> Solution::PreorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> ans;
    if(!root) return ans;
    while(root||!s.empty()){
        while(root){
            ans.push_back(root->val);
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        root=root->right;
    }
    return ans;
}

// Implementation 2
vector<int> Solution::PreorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> s;
    if(!root) return ans;
    s.push(root);
    while(!s.empty()){
        TreeNode* t=s.top();
        s.pop();
        ans.push_back(t->val);
        if(t->right) s.push(t->right);
        if(t->left) s.push(t->left);
    }
    return ans;
}

// Recursive Solution

void preOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    ans.push_back(root->val);
    preOrder(root->left,ans);
    preOrder(root->right,ans);    
}

vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preOrder(root,ans);
    return ans;
}
