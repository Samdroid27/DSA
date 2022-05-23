#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		string adj[n];
		for(int i=0;i<n;i++) cin>>adj[i];
		bool flag = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!i && !j){
					if(adj[i][j]=='R') goto A;
					else continue;
				}
				if(adj[i][j]=='R'){
					if(i+1 < n){
						for(int k=i+1;k<n;k++){
							for(int l = 0;l<j;l++){
								if(adj[k][l]=='R'){
									flag = false;
									goto A;
								}
							}
							
						}
					}
					goto A;
				}
 
			}
		}
		A:
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}