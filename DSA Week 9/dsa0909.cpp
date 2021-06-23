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
	int n,sum;
	cin>>n>>sum;
	vi a;
	vecinp(a,n);
	int dp[n+1][sum+1];
	for(int i=0;i<=sum;i++){
		dp[0][i]=INT_MAX-1;
		if(i!=0 && i%a[0]==0) dp[1][i]=i/a[0];
		else if(i==0) dp[1][i]=0;
		else dp[1][i]=INT_MAX-1;
	} 
	for(int i=1;i<=n;i++) dp[i][0]=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(i==0 || j==0) dp[i][j]=0;
			else{
				if(a[i-1]<=j){
					dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
				}
				else dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(dp[n][sum]==INT_MAX-1) cout<<-1<<endl;
	else cout<<dp[n][sum]<<endl;
	return 0;
}