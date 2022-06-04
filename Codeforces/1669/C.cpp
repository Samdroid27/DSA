#include <bits/stdc++.h>
using namespace std;
 
map<int,int> mp;
 
int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>(a[i]),a[i]%=2;
		if(n<=2){
			cout<<"YES"<<endl;
			continue;
		}
		int op=a[0],ep=a[1];
		bool flag=true;
		for(int i=2;i<n;i+=2){
			if(a[i]!=op){
				flag = false;
				break;
			}
			if(i+1<n && a[i+1]!=ep){
				flag = false;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}