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
 
void vecinp(vi &x,int l){
	for(int i=0;i<l;i++)
	{
		int k;
		cin>>k;
		x.pb(k);
	}
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int t,g;
	cin>>t>>g;
	vi a;
	vecinp(a,g);
	sort(all(a));
	int cnt=0;
	for(int i=0;i<g && t>=a[i];i++){
		cnt++;
		t-=a[i];
	}
	cout<<cnt<<endl;
	return 0;
}