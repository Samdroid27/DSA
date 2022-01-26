#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

vector<vector<pii>> adj;
vector<vector<int>> dp;


signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	dp = vector<vector<int>> (n+5,vector<int>(k+1,INT_MAX));
	adj = vector<vector<pii>>(n+1);

	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i=0;i<=k;i++) dp[0][i]=0;

	set<pair<int,pii>> pq;
	pq.insert({0,{0,0}}); // {dist,{node,coupons used}}

	while(!pq.empty()){
		int u = (pq.begin()->second).first;
		int j = (pq.begin()->second).second;
		pq.erase(pq.begin());
		for(pii ch:adj[u]){
			int v = ch.first;
			int w = ch.second;

			if(dp[v][j] > dp[u][j]+w){
				pq.erase({dp[v][j],{v,j}});
				dp[v][j]=dp[u][j]+w;
				pq.insert({dp[v][j],{v,j}});
			}

			if(j!=k && dp[v][j+1] > dp[u][j]){
				pq.erase({dp[v][j+1],{v,j+1}});
				dp[v][j+1]=dp[u][j];
				pq.insert({dp[v][j+1],{v,j+1}});
			}
		}
	}
	for(int i=0;i<n;i++){
		int ans = dp[i][0];
		for(int j=1;j<=k;j++) ans = min(ans,dp[i][j]);
		cout<<ans<<" ";
	}
	

}