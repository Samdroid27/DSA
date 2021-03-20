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
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n,k;
	cin>>n>>k;
	vector<vi> v(k);
	for(int i=0;i<n;i++){
		int inp;
		cin>>inp;
		v[inp%k].pb(inp);
	}
	for(int i=0;i<k;i++){
		sort(all(v[i]));
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
	}
	return 0;
}