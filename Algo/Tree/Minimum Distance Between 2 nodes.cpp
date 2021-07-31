/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
   
Node* LCA(Node* root,int a,int b){
    if(!root) return NULL;
    if(root->data == a || root->data == b) return root;
    Node* left = LCA(root->left,a,b);
    Node* right = LCA(root->right,a,b);
    if(left && right) return root;
    return left?left:right;
}

int distance(Node* root,int k,int d){
    if(!root) return -1;
    if(root->data == k) return d;
    int left = distance(root->left,k,d+1);
    int right = distance(root->right,k,d+1);
    return left!=-1?left:right;
}

int findDist(Node* root, int a, int b) {
    // Your code here
    Node* lca = LCA(root,a,b);
    int n1= distance(lca,a,0);
    int n2 = distance(lca,b,0);
    return n1+n2;
}