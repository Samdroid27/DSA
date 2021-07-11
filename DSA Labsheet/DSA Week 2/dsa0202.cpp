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



int pose(vector<vi>& v,int n){
	queue<int> q;
	int most=0;
	set<int> s;
	for(int i=1;i<=n;i++){
		q.push(i);
		while(q.size()>0){
			int k=q.front();
			s.insert(k);
			q.pop();
			for(int j:v[k]) 
				if(s.find(j)==s.end())
					q.push(j); 
		}
		int ans=s.size();
		most=max(most,ans);
		s.clear();
	}
	return most;
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int t,n;
	cin>>n>>t;
	vector<vi> v(n+1);
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
	}
	cout<<pose(v,n);
	return 0;
}