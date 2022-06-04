#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[n];
		vector<int> even;
		vector<int> odd;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(!(a[i]&1)) even.push_back(a[i]);
			else odd.push_back(a[i]);
		}
		int ans =0;
		if(even.size()){
			if(odd.size()) ans=even.size();
			else{
				int mn  = 40;
				for(int i:even){
					for(int j=0;j<=31;j++){
						if(i&(1<<j)){
							mn = min(mn,j);
						}
					}
				}
				ans = mn+even.size()-1;
			}
		}
		cout<<ans<<endl;		
	}
}