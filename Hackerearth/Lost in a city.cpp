#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

void solve(){
	int n,m,s;
	cin>>n>>m>>s;
	s--;
	vector<vector<int>> adj(n);
	vector<int> sweet(n);
	for(int i=0;i<n;i++) cin>>sweet[i];
	vector<int> d(n,-1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({sweet[s],s});
	d[s]=sweet[s];
	while(!pq.empty()){
		pii f = pq.top();
		int node = f.second;
		int t = f.first;
		pq.pop();
		for(int ch:adj[node]){
			int temp = max(t,sweet[ch]);
			if(temp<d[ch] || d[ch]==-1){
				d[ch]=temp;
				pq.push({d[ch],ch});
			}
		}
	}
	for(int i=0;i<n;i++) cout<<d[i]<<" ";
	cout<<endl;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}