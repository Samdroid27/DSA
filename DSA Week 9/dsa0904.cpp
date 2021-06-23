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
#define sep " "
 
using namespace std;

int Bounded01Knapsack(vi& val,vi& wt,int W,int n){
	int dp[n+1][W+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(wt[i-1]<=j){
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][W];
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
	int n,w;
	cin>>n>>w;
	vi val,wt;
	vecinp(wt,n);
	vecinp(val,n);
	cout<<Bounded01Knapsack(val,wt,w,n);
	return 0;
}