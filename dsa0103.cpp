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
	int t;
	cin>>t;
	int cnt=0,mx=0;;
	while(t--){
		char c;
		cin>>c;
		int n;
		cin>>n;
		if(c=='E'){
			cnt+=n;
			mx=max(mx,cnt);
		}
		else{
			cnt-=n;
			while(n--){
				int k;
				cin>>k;
			}
		}
	}
	cout<<mx<<endl;
	return 0;
}