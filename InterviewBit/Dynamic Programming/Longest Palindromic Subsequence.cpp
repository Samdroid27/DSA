int dp[1006][1006];

int LPS(string s,int f,int l){
   if(f>l) return 0;
   if(f==l) return 1;
   if(dp[f][l]!=0) return dp[f][l];
   if(s[f]==s[l]) return dp[f][l]=2+LPS(s,f+1,l-1);
   else return dp[f][l]=max(LPS(s,f+1,l),LPS(s,f,l-1));
}

int Solution::solve(string s) {
   memset(dp,0,sizeof(dp));
   return LPS(s,0,s.size()-1);   
}