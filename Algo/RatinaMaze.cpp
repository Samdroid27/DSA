#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define int long long
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
#define sep " "
 
using namespace std;

bool isSafe(int** arr,int x,int y,int n){
	if(x<n && y<n && arr[x][y]==1) return true;
	return false;
}

bool ratInAMaze(int **arr,int x,int y,int n,int **solArr){
	if(x==n-1 && y==n-1){
		solArr[x][y]=1;
		return true;
	}
	if(isSafe(arr,x,y,n)){
		solArr[x][y]=1;
		if(ratInAMaze(arr,x+1,y,n,solArr)){
			return true;
		}
		if(ratInAMaze(arr,x,y+1,n,solArr)) return true;
		solArr[x][y]=0;
		return false;
	}
	return false;
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n;
	cin>>n;
	int **arr = new int*[n];
	int **sol = new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		sol[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			sol[i][j]=0;
		}
	}
	ratInAMaze(arr,0,0,n,sol);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<sol[i][j]<<sep;
		}
		cout<<endl;
	}
	return 0;
}