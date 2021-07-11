#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define int long long
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
 
using namespace std;
 
int uglyNum(int n){
 	set<int> ugly;
 	ugly.insert(1);
 	int x=1;
 	while(n--){
 		x = *ugly.begin();
 		ugly.erase(x);
 		ugly.insert(x*2);
 		ugly.insert(x*3);
 		ugly.insert(x*5); 
 	}
 	return x;
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<uglyNum(n)<<endl;
	}
	return 0;
}