#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &val){
    int dp[val.size()+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=val.size();i++) dp[i][0]=1;
    for(int i=1;i<=n;i++) dp[0][1]=0;
    for(int i=1;i<=val.size();i++){
        for(int j=1;j<=n;j++){
            if(val[i-1]<=j){
                dp[i][j]=dp[i][j-val[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[val.size()][n];
}

int main() {
	int n;
	cin>>n;
	int l = log2(n);
	vector<int> val;
	for(int i=0;i<=l;i++){
	    val.push_back(1<<i);
	}
	cout<<solve(n,val)<<endl;
	return 0;
}
