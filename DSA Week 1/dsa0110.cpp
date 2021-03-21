#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define ll long long
#define vll vector<ll>
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
 
using namespace std;
 /*
	Check if a graph is bipartite or not using bfs
 */

bool bipartite(vector<vi> &G, int a[]){
	a[0]= 1;
	queue<int> q;
	q.push(0);
	int i=1;
	while(!q.empty()){
		int u = q.front();
        q.pop();
        // Find all non-colored adjacent vertices
        for (int v = 0; v < sz(G[u]); ++v)
        {
            // An edge from u to v exists and 
            // destination v is not colored
            if ( a[G[u][v]] == -1)
            {
                // Assign alternate color to this adjacent v of u
                a[G[u][v]] = 1 - a[u];
                q.push(G[u][v]);
            }
 
            // An edge from u to v exists and destination 
            // v is colored with same color as u
            else if (a[G[u][v]] == a[u])
                return false;
        }
	}
	return true;
}


i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n;
	cin>>n;
	int m;
	cin>>m;
 	vector<vi> v(n);
 	for(int i=0;i<m;i++){
 		int k,l;
 		cin>>k>>l;
 		v[k].pb(l);
 		v[l].pb(k);
 	}
 	int a[n];
 	memset(a,-1,sizeof(a));
 	bool flag= bipartite(v,a);
 	if(flag){
 		for(int i:a){
 			if(i==1) cout<<'R';
 			else cout<<'B';
 		}
 	}
 	else{
 		cout<<"NEED MORE COLORS";
 	}
	return 0;
}