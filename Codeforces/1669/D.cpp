
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool flag = false;
		int r=0,b=0;
		for(char c:s){
			if(c=='W'){
				if((r==0 && b!=0) || (b==0 && r!=0)){
					flag = true;
					break;
				}r=0,b=0;
			}
			else c=='B'?b++:r++;
		}
		if((r==0 && b!=0) || (b==0 && r!=0)) flag = true;
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}