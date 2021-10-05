/*
Hackerearth Question link: https://www.hackerearth.com/problem/algorithm/count-friends-190fcb36/

Count Friends
There are N students and M relationships of the form u v, which means that student u and student v are friends. 
If two students are not friends directly but they have a mutual friend, then they too become friends. 
Your task is to count the number of friends of the  student where 1<=i<=N.

Input:
The first line consists of two integers N and M denoting the number of students and the number of relationships respectively.
The next M lines consists of two integers u and v denoting that student u and student v are friends. u and v can never be equal and relationships are not repeated.

Output:
Print N space separated integers which tells us the number of friends of the  student.

Constraints:
1<=N<=1e5
1<=M<=1e5

Sample input                Sample Output
4 3                         0 2 2 2
4 3
2 4
2 3
*/

#include <bits/stdc++.h>
#define int long long 

using namespace std;

vector<int> par;

int find_parent(int n){
	if(par[n]<0) return n;
	return par[n]=find_parent(par[n]);
}

void make_union(int u,int v){
	int a = find_parent(u);
	int b = find_parent(v);
	if(a==b) return;
	par[a]+=par[b];
	par[b]=a;	
}

signed main() {
	int n,m;
	cin>>n>>m;
	par.resize(n+1);
	for(int i=1;i<=n;i++) par[i]=-1;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		make_union(a,b);
	}
	for(int i=1;i<=n;i++){
		int ans = find_parent(i);
		cout<<-1-par[ans]<<" ";
	}
	cout<<endl;
}