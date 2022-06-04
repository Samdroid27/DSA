vector<vector<bool>> isVisitedRed,isVisitedBlue;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void dfsRed(int x,int y,vector<vector<int>> &adj){
    isVisitedRed[x][y]=true;
    for(int i=0;i<4;i++){
        if((x+dx[i])>=0 && (y+dy[i])>=0 && (x+dx[i])<adj.size() && (y+dy[i])<adj[0].size()){
            if(adj[x+dx[i]][y+dy[i]]>=adj[x][y]){
                if(!isVisitedRed[x+dx[i]][y+dy[i]]) dfsRed(x+dx[i],y+dy[i],adj);
            }            
        }
    }
}

void dfsBlue(int x,int y,vector<vector<int>> &adj){
    isVisitedBlue[x][y]=true;
    for(int i=0;i<4;i++){
        if((x+dx[i])>=0 && (y+dy[i])>=0 && (x+dx[i])<adj.size() && (y+dy[i])<adj[0].size()){
            if(adj[x+dx[i]][y+dy[i]]>=adj[x][y]){
                if(!isVisitedBlue[x+dx[i]][y+dy[i]]) dfsBlue(x+dx[i],y+dy[i],adj);
            }            
        }
    }
}


int Solution::solve(vector<vector<int> > &A) {
    isVisitedRed = vector<vector<bool>> (A.size(),vector<bool>(A[0].size(),false));
    isVisitedBlue = vector<vector<bool>> (A.size(),vector<bool>(A[0].size(),false));
    int ans = 0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(i==0) dfsBlue(i,j,A);
            if(j==0) dfsBlue(i,j,A);
            if(i==A.size()-1) dfsRed(i,j,A);
            if(j==A[0].size()-1) dfsRed(i,j,A);
        }
    }
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(isVisitedRed[i][j] && isVisitedBlue[i][j]) ans++;
        }
    }
    return ans;
}

