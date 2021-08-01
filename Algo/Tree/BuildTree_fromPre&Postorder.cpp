/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int> &inorder,int curr,int start, int end){
    for(int i= start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

TreeNode* build(vector<int> &postorder,vector<int> &inorder,int start,int end,int &p){
    if(start > end) return NULL;
    int curr = postorder[p--];
    TreeNode* node = new TreeNode(curr);
    int pos = search(inorder,curr,start,end);
    node->right = build(postorder,inorder, pos+1,end,p);
    node->left = build(postorder,inorder,start,pos-1,p);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int index=postorder.size()-1;
    if(postorder.empty()|| inorder.empty()) return NULL;
    return build(postorder,inorder,0,postorder.size()-1,index); 
}