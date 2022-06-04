#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int e = 0;
		if(b<c || d<a) e=c+a;
		else e=max(c,a);
		cout<<e<<endl;
 
	}
}