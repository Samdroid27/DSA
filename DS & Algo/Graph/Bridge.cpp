/*
Codeforces Problem : 118/E. Bertown roads
Problem link: https://codeforces.com/contest/118/problem/E

Bertown has n junctions and m bidirectional roads. We know that one can get from any junction to any other one by the existing roads.

As there were more and more cars in the city, traffic jams started to pose real problems. To deal with them the government decided to make the traffic one-directional on all the roads, thus easing down the traffic. Your task is to determine whether there is a way to make the traffic one-directional so that there still is the possibility to get from any junction to any other one. If the answer is positive, you should also find one of the possible ways to orient the roads.

Input
The first line contains two space-separated integers n and m (2≤n≤1e5,n-1≤m≤3·1e5) which represent the number of junctions and the roads in the town correspondingly. Then follow m lines, each containing two numbers which describe the roads in the city. Each road is determined by two integers ai and bi (1≤ai,bi≤n,ai≠bi) — the numbers of junctions it connects.

It is guaranteed that one can get from any junction to any other one along the existing bidirectional roads. Each road connects different junctions, there is no more than one road between each pair of junctions.

Output
If there's no solution, print the single number 0. Otherwise, print m lines each containing two integers pi and qi — each road's orientation. That is the traffic flow will move along a one-directional road from junction pi to junction qi. You can print the roads in any order. If there are several solutions to that problem, print any of them.

Logic : Check if there's a bridge in the graph
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> ans;
vector<bool> visited;
vector<int> low,in;
int timer=0;

bool dfs(int u,int p){
    visited[u]=true;
    in[u] = low[u] = timer++;
    for(int child:adj[u]){
        if(child==p) continue;
        if(visited[child]){
            low[u]=min(low[u],in[child]);
            if(in[u]>in[child]) ans.push_back({u,child});
        }else{
           bool f = dfs(child,u);
           if(!f)return f;
           if(low[child]>in[u]) return false;
           low[u]=min(low[u],low[child]);
           ans.push_back({u,child});
        }
    }
    return true;
}

int main() {
    int t=1;
    // cin>>t;
    while(t--){
        int n,e;
    	cin>>n>>e;
    	adj = vector<vector<int>>(n+1);
    	for(int i=0;i<e;i++){
    	    int u,v;
    	    cin>>u>>v;
    	    adj[u].push_back(v);
    	    adj[v].push_back(u);
    	}
    	visited.resize(n+1,false);
    	in.resize(n+1);
    	low.resize(n+1);
    	bool flag = dfs(1,-1);
    	if(flag){
    	    for(auto i:ans){
    	        cout<<i.first<<" "<<i.second<<endl;
    	    }
    	}else cout<<0<<endl;
    }

	return 0;
}
