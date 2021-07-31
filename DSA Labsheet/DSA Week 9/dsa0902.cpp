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
const int N=1e5+1;
int dp[N];

int minZero(int n){
    if(dp[n]!=-1) return dp[n];
    if(n==0) return 0;
    vector<int> a;
    int num = n;
    while(num){
        int d = num%10;
        if(d) a.push_back(d);
        num /=10;
    }
    int ans=INT_MAX;
    for(int i:a){
        ans = min(ans,minZero(n-i));
    }
    return dp[n]=1+ans;
}

i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<minZero(n)<<endl;
    return 0;
}
