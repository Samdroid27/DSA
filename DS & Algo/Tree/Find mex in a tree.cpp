/* Codenation Campus Internship Question
3. Find MEX in tree
-> Given a tree with 10000 nodes , root 0 for each node find mex of its subtree i.e smallest value not present in subtree
->All nodes have distinct values, 0<= val_i < n

logic 
->For every node which is not an ancestor of value ZERO, mex = 0
->For ancestors of ZERO calculate mex linearly using set

Sample Input:
6
0 1 
1 2 
0 3
3 4 
3 5
4 3 5 1 0 2
Sample Output:
6 0 0 3 1 0 

*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> in,out,par,mex,val;
int timer;
int zero; // position of zero
set<int> s;

void dfs(int v,int p){
    in[v]=timer++;
    par[v]=p;
    for(int i:adj[v]){
        if(i!=p) dfs(i,v);
    }
    out[v]=timer++;
}

bool isAncestor(int u,int v){
    return in[u]<in[v] && out[u]>out[v];
}

// function to erase element from subtree value set 

void calc(int u){
    for(auto &v:adj[u])
        if(par[u]!=v && !isAncestor(v,zero))
            calc(v);
    s.erase(val[u]);
}

void solve(){
    cin>>n;
    adj = vector<vector<int>>(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    val.resize(n);
    for(int i=0;i<n;i++) cin>>val[i];
    zero = find(val.begin(),val.end(),0)-val.begin(); // index of zero
    
    timer = 1;
    in.resize(n);
    out.resize(n);
    par.resize(n);
    mex.resize(n,n);
    dfs(0,-1);
    
    for(int i=0;i<=n;i++) s.insert(i);
    for(int i=0;i<n;i++){
        if(isAncestor(zero,i)) s.erase(val[i]);
        if(!isAncestor(i,zero)) mex[i]=0;
    }
    s.erase(0);
    mex[zero]=*s.begin();
    
    int cur = par[zero];
    while(cur!=-1){
        calc(cur);
        mex[cur]=*s.begin();
        cur = par[cur];
    }
    for(int i: mex) cout<<i<<" ";
    cout<<endl;
}

signed main() {
	solve();
}
