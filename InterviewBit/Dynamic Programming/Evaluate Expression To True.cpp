int N=1e3+3;
int dp[200][200][2];

int solve(string &s,int i,int j, bool isTrue){
    if(i>j) return 0;
    if(i==j){
        return isTrue ? s[i]=='T' : s[i]=='F';
    }
    int ans = 0;
    for(int k=i+1;k<j;k+=2){
        int lT = dp[i][k-1][1]!=-1 ? dp[i][k-1][1] : solve(s,i,k-1,true);
        int lF = dp[i][k-1][0]!=-1 ? dp[i][k-1][0] : solve(s,i,k-1,false);
        int rT = dp[k+1][j][1]!=-1 ? dp[k+1][j][1] : solve(s,k+1,j,true);
        int rF = dp[k+1][j][0]!=-1 ? dp[k+1][j][0] : solve(s,k+1,j,false);
        if(s[k]=='&'){
            if(isTrue) ans+= lT*rT;
            else ans+= lT*rF + lF*rF + lF*rT;
        }else if(s[k]=='|'){
            if(isTrue) ans+= lT*rT + lF*rT + lT*rF;
            else ans+= lF*rF;
        }
        else{
            if(isTrue) ans+= lT*rF + lF*rT;
            else ans+= lF*rF + lT*rT;
        }
    }
    return dp[i][j][isTrue]=ans%N;

}

int Solution::cnttrue(string A) {
    memset(dp,-1,sizeof(dp));
    return solve(A,0,A.length()-1,true);
}
