int Solution::adjacent(vector<vector<int> > &A) {
    vector<int> dp(A[0].size());
    for(int i=0;i<A[0].size();i++) dp[i]=max(A[0][i],A[1][i]);
    for(int i=0;i<A[0].size();i++){
        int mx = 0;
        for(int j=0;j<i-1;j++){
            mx = max(mx,dp[j]);
        }
        dp[i]+=mx;
    }
    return *max_element(dp.begin(),dp.end());
}