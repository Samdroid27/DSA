/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        if(root->val < low) return trimBST(root->right,low,high);
        if(root->val > high) return trimBST(root->left,low,high);
        while(root->left && root->left->val<low) root->left=root->left->right;
        while(root->right && root->right->val>high) root->right=root->right->left;
        trimBST(root->left,low,high);
        trimBST(root->right,low,high);
        return root;
    }
};