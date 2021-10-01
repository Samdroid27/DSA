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

bool isSafe(vector<vi> &a,int x,int y,int n){
	for(int i=0;i<x;i++) if(a[i][y]==1) return false;

	int row=x,col=y;
	while(row>=0 && col>=0){
		if(a[row][col]==1) return false;
		row--,col--;
	}
	row=x,col=y;
	while(row>=0 && col<n){
		if(a[row][col]==1) return false;
		row--,col++;
	}
	return true;
}

bool nQueen(vector<vi> &a,int x,int n){
	if(x>=n) return true;

	for(int col=0;col<n;col++){
		if(isSafe(a,x,col,n)){
			a[x][col]=1;
			if(nQueen(a,x+1,n)){
				return true;
			}
			a[x][col]=0; 
		}	
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
	vvi(a,n,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	nQueen(a,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<sep;
		}
		cout<<endl;
	}
	return 0;
}