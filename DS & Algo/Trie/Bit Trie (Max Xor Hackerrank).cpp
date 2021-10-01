// Find max XOR of elements of array and a given no.
/*Sample Input 0

3            = No. of the elements of the array (n) 
0 1 2        = Array
3            = No. of queries(m)
3            = m queries follow
7
2
Sample Output 0

3 
7 
3 
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

class Trie{
    public:
        Trie* child[2];
        Trie(){
            child[0]=NULL;
            child[1]=NULL;
        }
};

void insert(Trie* root,int val){
    for(int i=32;i>=0;i--){
        int bit = ((val>>i) & 1);
        if(!root->child[bit]){
            root->child[bit]=new Trie();
        }
        root = root->child[bit];
    }
}

int maxXor(Trie* root,int val){
    int ans = 0;
    for(int i=32;i>=0;i--){
        int bit = ((val>>i)&1);
        if(root->child[bit^1]){
            ans += (1LL<<i);
            root = root->child[bit^1];
        }else{
            root= root->child[bit];
        }
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    Trie* root = new Trie();
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(root,a[i]);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        cout<<maxXor(root,k)<<endl;
    }
}
