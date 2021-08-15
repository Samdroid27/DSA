/*
SPOJ Problem : Submerging Islands
Link :https://www.spoj.com/problems/SUBMERGE/

Vice City is built over a group of islands, with bridges connecting them.
As anyone in Vice City knows, the biggest fear of vice-citiers is that some day the islands will submerge.
The big problem with this is that once the islands submerge, some of the other islands could get disconnected. 
You have been hired by the mayor of Vice city to tell him how many islands, when submerged, will disconnect parts of Vice City. 
You should know that initially all the islands of the city are connected.

Input
The input will consist of a series of test cases. 
Each test case will start with the number N (1 ≤ N ≤ 10^4) of islands, and the number M of bridges (1 ≤ M ≤ 10^5).
Following there will be M lines each describing a bridge. 
Each of these M lines will contain two integers Ui, Vi (1 ≤ Ui,Vi ≤ N), indicating that there is a bridge connecting islands Ui and Vi.
The input ends with a case where N = M = 0.

Output
For each case on the input you must print a line indicating the number of islands that, when submerged, will disconnect parts of the city.

Input:
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0

Output:
0
1

Logic : Count articulation points.
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> ans;
vector<bool> visited;
vector<int> low,in;
int timer=1;
set<int> ap;

void dfs(int u,int p){
    visited[u]=true;
    in[u] = low[u] = timer++;
    int childcnt=0;
    for(int child:adj[u]){
        if(child==p) continue;
        if(visited[child]){
            low[u]=min(low[u],in[child]);
        }else{
           dfs(child,u);
           childcnt++;
           low[u]=min(low[u],low[child]);
           if(in[u]<=low[child] && p!=-1){
               ap.insert(u);
           }
        }
    }
    if(p==-1 && childcnt>1) ap.insert(u);
}

int main() {
    while(true){
        int n,e;
    	cin>>n>>e;
    	if(n==0 && e==0) break;
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
    	for(int i=0;i<=n;i++){
    	    visited[i]=false;
    	    in[i]=0;
    	    low[i]=0;
    	}
    	ap.clear();
    	timer = 1;
    	for(int i=1;i<=n;i++) 
    	if(!visited[i])
        dfs(1,-1);
        cout<<ap.size()<<endl;
    }

	return 0;
}
