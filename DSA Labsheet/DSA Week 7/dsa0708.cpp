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

void vecinp(vi &x,int l){
	for(int i=0;i<l;i++)
	{
		int k;
		cin>>k;
		x.pb(k);
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
	vi a;
	vecinp(a,n);
	queue<int> t;
	t.push(a[0]);
	int k=0;
	int l=0;int r=0;
	while(t.size()>0 && k<n){
		int s=t.size();
		for(int i=0;i<s;i++){
			if(i==0) l+=t.front();
			if(i==s-1) r+=t.front();
			t.pop();
			if(a[2*k+1]!=-1 && ((2*k+1)<n))t.push(a[2*k+1]);
			if(a[2*k+2]!=-1 && ((2*k+2)<n))t.push(a[2*k+2]);
			k++;
		}
	}
	cout<<abs(l-r)<<endl;
	return 0;
}