/**************************************************************
The solution is dynamic programming with time complexity - O(n*n)

dp[i][j] = number of sequences for S[1,i] with balance j. '(' increase the balance by 1 and ')' decrease the balance by 1.

therefore,
if (S[i] == '(') dp[i][j] = dp[i-1][j-1]
if (S[i] == ')') dp[i][j] = dp[i-1][j+1]
if (S[i] == '?') dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

Then, the total count of RBS for the string are dp[n][0].
**************************************************************/

#include <bits/stdc++.h>
#define int long long

int N = 1e9+7;

using namespace std;

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int dp[n+1][n+1];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='?' || s[i-1]=='(')
				for(int j=1;j<=n;j++) dp[i][j]=dp[i-1][j-1];
			if(s[i-1]=='?' || s[i-1]==')')
				for(int j=0;j<n-1;j++) (dp[i][j] += dp[i-1][j+1]) %= N;
		}
		cout << dp[n][0] << '\n';
	}
}