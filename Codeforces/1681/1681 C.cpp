#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		vector<pair<int,int>> v;
		int flag = 0;
		for(int i=0;i<n;i++){
			int k = *max_element(a.begin(),a.end()-i);
			int l = *max_element(b.begin(),b.end()-i);
			int ind=-1;
			for(int j=0;j<n-i;j++){
				if(a[j]==k && b[j]==l){
					ind=j;
					break;
				}
			}
			if(ind==-1){
				flag = 1;
				break;
			}
			else{
				if(ind!=n-i-1){
					swap(a[n-i-1],a[ind]);
					swap(b[n-i-1],b[ind]);
					v.push_back({n-i,ind+1});
				}
				
			}
		}
		if(flag) cout<<"-1"<<endl;
		else{
			cout<<v.size()<<endl;
			for(pair<int,int> i:v){
				cout<<i.first<<" "<<i.second<<endl;
			}
		}
	}
}