#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		string a[(2*n)+1];
		int mp[26];
		char ans ='a';
		memset(mp,0,sizeof(mp));
		for(int i=0;i<=(2*n);i++) cin>>a[i];
		for(int i=0;i<=(2*n);i++) for(char c:a[i]) mp[c-'a']++;
		for(int i=0;i<26;i++) if(mp[i]&1) ans+=i;
		cout<<ans<<endl;
	}
}