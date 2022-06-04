#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		string s[2];
		cin>>s[0]>>s[1];
		for(int i=0;i<2;i++){
			while(s[0].back()=='.' && s[1].back()=='.'){
				s[0].pop_back();
				s[1].pop_back();
			}
			reverse(s[0].begin(),s[0].end());
			reverse(s[1].begin(),s[1].end());
		}
		n = s[0].size();
		vector<vector<int>> dp(n,vector<int>(2,INF));
		int cost[n][2];
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				cost[i][j]=(s[j][i]=='*');
			}
		}
		dp[0][1]=cost[0][0];
		dp[0][0]=cost[0][1];
		for(int i=1;i<n;i++){
			dp[i][0]=min(dp[i-1][0]+1+cost[i][1],dp[i-1][1]+2);
			dp[i][1]=min(dp[i-1][1]+1+cost[i][0],dp[i-1][0]+2);
		}
		cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
	}
}