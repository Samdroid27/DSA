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


void dfs(int i,vector<vi> &x,int a[],vi &c){
	a[i]=true;
	c[sz(c)-1]++;
	for(int j=0;j<sz(x[i]);j++){
		if(!a[x[i][j]]){
			dfs(x[i][j],x,a,c);
		}
	}
}
 
vi find(vector<vi> x,int n,int a[]){
	vi cluster;
	for(int i=0;i<n;i++){
		if(!a[i]){
			cluster.pb(0);
			dfs(i,x,a,cluster);
		}
	}
	return cluster;
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
 	int a[n];
 	memset(a,false,sizeof(a));
 	for(int i=0;i<m;i++){
 		int k,l;
 		cin>>k>>l;
 		v[k].pb(l);
 		v[l].pb(k);
 	}
 	vi cluster=find(v,n,a);
 	cout<<sz(cluster)<<endl;
 	for(int i:cluster){
 		cout<<i<<" ";
 	}
	return 0;
}