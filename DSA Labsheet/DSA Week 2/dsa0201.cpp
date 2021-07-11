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

int ghot(int n){
	int div[]={0,0};
	int x=0;
	for(int i=n-1;i>1;i--){
		if(n%i==0){
			div[x++]=i;
		}
		if(x>1) break;
	}
	if(div[1]>0){
		return ghot(div[1])+ghot(div[0]);
	}else{
		return n;
	}
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n;
	cin>>n;
	cout<<ghot(n);
	return 0;
}