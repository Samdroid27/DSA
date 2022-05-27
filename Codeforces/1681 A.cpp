#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n;
		int mxa=INT_MIN,mxb=INT_MIN;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			mxa = max(mxa,k);
		}
		cin>>m;
		for(int i=0;i<m;i++){
			int k;
			cin>>k;
			mxb = max(mxb,k);
		}
		if(mxa>mxb){
			cout<<"Alice"<<endl;
			cout<<"Alice"<<endl;
		}else if(mxa<mxb){
			cout<<"Bob"<<endl;
			cout<<"Bob"<<endl;
		}else{
			cout<<"Alice"<<endl;
			cout<<"Bob"<<endl;
		}
	}
}