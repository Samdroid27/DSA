vector<vector<int>> a;
vector<bool> visited;
bool dfs(int u,int A){
    visited[u]=true;
    bool ans = false;
    for(int child:a[u]){
        if(child==A) return true;
        if(!visited[child]) ans |= dfs(child,A);
    }
    return ans;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    a = vector<vector<int>>(A+1);
    for(vector<int> i:B){
        a[i[0]].push_back(i[1]);
    }
    visited = vector<bool> (A+1,false);
    return dfs(1,A) ? 1 : 0;
}
