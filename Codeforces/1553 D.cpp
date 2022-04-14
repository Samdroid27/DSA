#include <bits/stdc++.h>
 
using namespace std;
 
 
bool check(string &s,int i,string &t,int j){
	if(j<0) return true;
	if(i<0) return false;
	if(s[i]==t[j]){
		return check(s,i-1,t,j-1);
	}
	return check(s,i-2,t,j);
}
 
int main() {
	int test;
	cin>>test;
	while(test--){
		string s,t;
		cin>>s>>t;
		if(check(s,s.size()-1,t,t.size()-1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}