#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		if(n&1 || n==2){
			cout<<-1<<endl;
			continue;
		}
		else{
			int mx = n/6;
			int mxr = n%6;
			if(mxr==2) mx++;
			else if(mxr==4) mx++;
			int mn = n/4;
			cout<<mx<<" "<<mn<<endl;
		}
	}
}