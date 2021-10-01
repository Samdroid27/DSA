// Inorder traversal of Binary Tree 

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    while(A || !s.empty()){
        while(A){
            s.push(A);
            A= A->left;
        }
        A=s.top();
        s.pop();
        ans.push_back(A->val);
        A=A->right;
    }
    return ans;
}

// Implementation 2
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty()){
        TreeNode* t = s.top();
        if(t){
            s.push(t->left);
            continue;
        }
        else{
            s.pop();
            if(!s.empty()){
                t=s.top();
                if(t)ans.push_back(t->val);
                s.pop();
                if(t)s.push(t->right);
            }
        }
    }
    return ans;
}

// Recursive Solution

void inorder(TreeNode* A,vector<int> &ans){
    if(!A) return;
    inorder(A->left,ans);
    ans.push_back(A->val);
    inorder(A->right,ans);
}
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    inorder(A,ans);
    return ans;
}
