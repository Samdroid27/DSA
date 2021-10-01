/*
https://codeforces.com/problemset/problem/894/A

Bort wants to know how many subsequences "QAQ" are in the string Diamond has given. Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.

Input
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.

Examples
inputCopy
QAQAQYSYIOIWIN
outputCopy
4
inputCopy
QAQQQZZYNOIWIN
outputCopy
3
Note
In the first example there are 4 subsequences "QAQ": "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN".

*/


#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define ll long long
#define vll vector<ll>
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
 
using namespace std;

int overlappingSubsequence(string a, string b, int m,int n){
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++) dp[i][0]=1;
	for(int j=1;j<=n;j++) dp[0][j]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[m][n];
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	string s;
	cin>>s;
	cout<<overlappingSubsequence(s,"QAQ",sz(s),3);
	return 0;
}