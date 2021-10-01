/*
Gold Mine Problem 
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move
1.to the cell diagonally up towards the right 
2.to the right
3.to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.

Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination: 
The path is {(1,0) -> (2,1) -> (2,2)}
*/

class Solution{
public:
    int dp[51][51];
    int dfs(vector<vector<int>> &g, int i,int j){
        if(i<0 || j<0 || i>=g.size()|| j>=g[i].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = max({
            dfs(g,i+1,j+1),
            dfs(g,i,j+1),
            dfs(g,i-1,j+1)
        });
        return dp[i][j]=g[i][j]+res;
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int res =0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            res = max(res,dfs(M,i,0));
        }
        return res;
    }
};