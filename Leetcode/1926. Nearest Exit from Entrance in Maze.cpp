class Solution {
public:
    int dirx[4]={-1,0,1,0};
    int diry[4]={0,-1,0,1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[entrance[0]][entrance[1]]=true;
        int dist = -1;
        while(q.size()>0){
            int level = q.size();
            dist++;
            while(level--){
                pair<int,int> cell = q.front();
                q.pop();
                if(cell.first!=entrance[0] || cell.second!=entrance[1]){
                    
                    if((cell.first==0 || cell.first==m-1) || (cell.second==0 || cell.second==n-1)){
                        return dist;
                    }
                }
                
                for(int i=0;i<4;i++){
                    if((cell.first+dirx[i]>=0 && cell.first+dirx[i]<=m-1) 
                    && (cell.second+diry[i]>=0 && cell.second+diry[i]<=n-1)
                    &&  !visited[cell.first+dirx[i]][cell.second+diry[i]]
                    && maze[cell.first+dirx[i]][cell.second+diry[i]]=='.'){
                        
                        q.push({cell.first+dirx[i],cell.second+diry[i]});
                        visited[cell.first+dirx[i]][cell.second+diry[i]]=true;
                    }
                }
            } 
        }
        return -1;
    }
};