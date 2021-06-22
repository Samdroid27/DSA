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
 
void Seive(int n){
	int a[n+1];
	a[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	for(int i=2;i<n;i++){
		if(a[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(a[j]==j){
					a[j]=i;
				}
			}
		}
	}
	while(n>1){
		cout<<a[n]<<" ";
		n=n/a[n];
	}
	cout<<endl;
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Seive(n);
	}
	return 0;
}