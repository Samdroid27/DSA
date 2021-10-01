// Postorder traversal of Binary Tree 

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

// Implementation 1 using 2 stacks

vector<int> Solution::postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s1,s2;
    vector<int> ans;
    if(!root) return ans;
    s1.push(root);
    while(!s1.empty()){
        TreeNode* t=s1.top();
        s2.push(t);
        s1.pop();
        if(t->left) s1.push(t->left);
        if(t->right) s1.push(t->right);
    }
    while(!s2.empty()){
        TreeNode* t= s2.top();
        ans.push_back(t->val);
        s2.pop();
    }
    return ans;
}


// Implementation 2 using 1 stack

vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> ans;
    if(!root) return ans;
    do{
        while(root){
            if(root->right)s.push(root->right);
            s.push(root);
            root= root->left;
        }
        root = s.top();
        s.pop();
        if(root->right && !s.empty() && root->right==s.top()){
            TreeNode* ryt = s.top();
            s.pop();
            s.push(root);
            root = ryt;
        }
        else{
            ans.push_back(root->val);
            root = NULL;
        }
    }while(!s.empty());
    return ans;
}

// Recursive Solution

void Postorder(TreeNode* A,vector<int> &ans){
    if(!A) return;
    Postorder(A->left,ans);
    Postorder(A->right,ans);
    ans.push_back(A->val);
}

vector<int> Solution::PostorderTraversal(TreeNode* A) {
    vector<int> ans;
    Postorder(A,ans);
    return ans;
}
