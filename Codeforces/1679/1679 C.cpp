#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	set<int> nx,ny;
	for(int i=0;i<=n;i++){
		nx.insert(i);
		ny.insert(i);
	}
	vector<int> cntx(n,0),cnty(n,0);
	while(q--){
		int query;
		cin>>query;
		if(query==1){
			int x,y;
			cin>>x>>y;
			x--,y--;
			if(!cntx[x]) nx.erase(x);
			if(!cnty[y]) ny.erase(y);
			cntx[x]++,cnty[y]++;
		}else if(query == 2){
			int x,y;
			cin>>x>>y;
			x--,y--;
			cntx[x]--,cnty[y]--;
			if(!cntx[x]) nx.insert(x);
			if(!cnty[y]) ny.insert(y);
		}else{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			x1--,y1--;
			if (*nx.lower_bound(x1) >= x2 || *ny.lower_bound(y1) >= y2){
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
}