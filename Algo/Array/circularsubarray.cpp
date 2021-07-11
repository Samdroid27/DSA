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
 
int kadane(vi a,int n){
	int mx=INT_MIN,curr=0;
	for(int i=0;i<n;i++){
		curr+=a[i];
		if(curr<0) curr=0;
		mx=max(curr,mx);
	}
	return mx;
}
 
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi a;
		
		int wrapSum=0,nonWrapSum=0;
		vecinp(a,n);
		wrapSum=kadane(a,n);
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
			a[i]=-a[i];
		}
		nonWrapSum= sum + kadane(a,n);
		
		cout<<max(wrapSum,nonWrapSum)<<endl;
	}
	return 0;
}