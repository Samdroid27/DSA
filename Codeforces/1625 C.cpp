#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

signed main() {
	int n,l,k;
	cin>>n>>l>>k;
	vector<int> km(n),post(n);
	for(int i=0;i<n;i++) cin>>km[i];
	km.push_back(l);
	for(int i=0;i<n;i++) cin>>post[i];
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=INF;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(!j){
				dp[i][j]=dp[i-1][j]+((km[i]-km[i-1])*post[i-1]);
				continue;
			}
			for(int prev = i-1;prev>=0;prev--){
				int rm = i-prev-1;
				if(j>=rm){
					dp[i][j]=min(dp[i][j],dp[prev][j-rm]+((km[i]-km[prev])*post[prev]));
				}
			}
		}
	}
	int ans = INF;
	for(int i=0;i<=k;i++) ans = min(ans,dp[n][i]);
	cout<<ans<<endl;
} 