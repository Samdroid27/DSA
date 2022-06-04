#include<bits/stdc++.h>
#define int long long

using namespace std;


int wt(string &s,int i,int k,char t){
	if(!k) return 0;
	if(i>=s.size()) return -1;
	if(t>'z') return -1;
	if(s[i]>=t){
		int val = wt(s,i+1,k-1,s[i]+2);
		if(val!=-1){
			return val+(s[i]-'a'+1);
		}else return -1;
	}else return wt(s,i+1,k,t);
}

signed main() {
	int test=1;
	// cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		int w = wt(s,0,k,'a');
		cout<<w<<endl;

	}
}