/*
Kahn's Algorithm for TOPOLOGICAL SORTING.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;
vector<int> in;

void kahn(){
    priority_queue<int,vector<int>, greater<int> > q;
    for(int i=1;i<in.size();i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int curr = q.top();
        q.pop();
        ans.push_back(curr);
        for(int i:adj[curr]){
            in[i]--;
            if(!in[i]) q.push(i);
        }
        
    }
}


int main() {
    int n,e;
	cin>>n>>e;
	adj = vector<vector<int>>(n+1);
	in.resize(n+1,0);
	for(int i=0;i<e;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    in[v]++;
	}
    kahn();
    if(ans.size()!=n){
        cout<<"Sandro fails.";
        return 0;
    }
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
	return 0;
}
