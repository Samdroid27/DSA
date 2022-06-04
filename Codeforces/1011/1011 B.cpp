#include<bits/stdc++.h>
 
using namespace std;
 
map<int,int> mp;
map<int,int>::iterator it;
int n;
 
bool isPossible(int mid){
	int cnt=0;
	for(it = mp.begin();it!=mp.end();it++){
		int val = it->second;
		cnt += val/mid;
		if(cnt>=n) return true;
	}
	return false;
}
 
signed main() {
	int m;
	cin>>n>>m;
	vector<int> a(m);
	
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(mp.find(a[i])==mp.end()) mp[a[i]]=1;
		else mp[a[i]]++;
	}
	if(m<n){
		cout<<0<<endl;
	}else if(m==n){
		cout<<1<<endl;
	}
	else{
		int r = m/n;
		int l = 0;
		int ans = 0;
		while(l<=r){
			int mid = (l+r)/2;
			if(mid==0){
				l = mid+1;
				continue;
			}
			if(isPossible(mid)){
				ans = mid;
				l = mid+1;
			}else r = mid-1;
		}
		cout<<ans;
	}
	
}