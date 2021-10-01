//DFS on a grid
/*
CSES problem link : https://cses.fi/problemset/task/1192/
*/

#include <bits/stdc++.h>
using namespace std;

int N,M;

vector<vector<bool> > visited;
vector<string> grid;
vector<int> dx ={-1,0,1,0};
vector<int> dy = {0,-1,0,1};

bool isValid(int x,int y){
    if(x>=N || x<0 || y>=M || y<0) return false;
    if(visited[x][y] || grid[x][y]=='#') return false;
    return true;
}

void dfs(int x,int y){
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        if(isValid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main() {
	cin>>N>>M;
	grid.resize(N);
	visited = vector<vector<bool>>(N,vector<bool>(M));
	for(int i=0;i<N;i++) cin>>grid[i];
	int cnt=0;
	for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++){
	        if(isValid(i,j)){
	            cnt++;
	            dfs(i,j);
	        }
	    }
	}
	cout<<cnt<<endl;
	return 0;
}
