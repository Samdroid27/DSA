#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1005][2005];

signed main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int val[n],price[n];
		for(int i=0;i<n;i++) cin>>val[i]>>price[i];
		int sum = 0;
		int sump = 0;
		for(int i=0;i<n;i++) sum+=val[i],sump+=price[i];
		for(int i=0;i<=n;i++) for(int j=0;j<=2*n;j++) dp[i][j]=sump;
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2*n;j++){
				if(val[i-1]+1<=j){
					dp[i][j]=min(dp[i-1][j],dp[i-1][j-val[i-1]-1]+price[i-1]);
				}
				else dp[i][j]=dp[i-1][j];
			}
		}
		int ans = INT_MAX;
		for(int i=n;i<=2*n;i++){
			ans = min(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
}