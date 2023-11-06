class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return 0;
        int dp[maxMove+1][m+1][n+1];
        memset(dp,0,sizeof(dp));
        int N = 1e9+7;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[1][i][j]++;
                if(j==0 ) dp[1][i][j]++;
                if(i==m-1) dp[1][i][j]++;
                if(j==n-1) dp[1][i][j]++;
            }
        }
        for(int i=2;i<=maxMove;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(j>0) (dp[i][j][k] += dp[i-1][j-1][k] ) %= N;
                    if(k>0) (dp[i][j][k] += dp[i-1][j][k-1] ) %= N;
                    if(j<m-1) (dp[i][j][k] += dp[i-1][j+1][k] ) %= N;
                    if(k<n-1) (dp[i][j][k] += dp[i-1][j][k+1] ) %= N;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=maxMove;i++) (ans += dp[i][startRow][startColumn]) %= N;
        return ans;
    }
};