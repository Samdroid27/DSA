/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> construct(int start,int end){
    vector<TreeNode*> arr;

    if(start>end){
        arr.push_back(NULL);
        return arr;
    }

    for(int i=start;i<=end;i++){
        vector<TreeNode*> leftSubTree = construct(start,i-1);
        vector<TreeNode*> rightSubTree = construct(i+1,end);
        for(auto it: leftSubTree){
            for(auto ij: rightSubTree){
                TreeNode* root = new TreeNode(i);
                root->left = it;
                root->right = ij;
                arr.push_back(root);
            }
        }
    }
    return arr;
}


vector<TreeNode*> Solution::generateTrees(int n) {
    vector<TreeNode*> vv;
    if(!n) return vv;
    return construct(1,n);
}