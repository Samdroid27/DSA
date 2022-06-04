vector<vector<int>> adj;
vector<bool> visited,recStack;

bool dfs(int u){
    if(!visited[u]){
        visited[u]=true;
        recStack[u]=true;
        for(int child:adj[u]){
            if(!visited[child] && dfs(child)) return true;
            else if(recStack[child]) return true;
        }
    }
    recStack[u]=false;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    adj = vector<vector<int>>(A+1);
    visited = vector<bool>(A+1,false);
    recStack = vector<bool>(A+1,false);
    for(auto i:B){
        adj[i[0]].push_back(i[1]);
    }
    for(int i=1;i<=A;i++){
        if(!visited[i] && dfs(i)) return 1;
    }
    return 0;
}
