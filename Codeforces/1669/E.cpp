#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[11][11];
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			a[s[0]-'a'][s[1]-'a']++;
		}
		int ans = 0;
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				for(int k=0;k<11;k++){
					if(k<i) ans+=a[k][j]*a[i][j];
					if(k<j) ans+=a[i][k]*a[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
}