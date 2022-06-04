#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	int n,m;
	cin>>n>>m;
	int sum = 0;
	int cur = 0;
	while(n--){
		int k;
		cin>>k;
		sum += k;
		int td = sum/m;
		cout<<td-cur<<" ";
		cur=td;
	}
}