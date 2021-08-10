// In base ten, the i-th through j-th characters of S form an integer that is a multiple of 2019.

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N =2019;

int32_t main() {
	string s;
	cin>>s;
	int suf=0;
	int pot=1;
	std::vector<int > mp(N);
	mp[suf]++;
	int ans =0;
	for(int i=s.size()-1;i>=0;i--){
	    int d = s[i]-'0';
	    suf = (suf+ d*pot)%N;
	    pot = (pot*10)%N;
	    ans+=mp[suf];
	    mp[suf]++;
	}
	cout<<ans<<endl;
	return 0;
}
