#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int ans = 0,a=0,b=0;
		for(int i=0;i<=31;i++){
			if(n&(1<<i)){
				a=i;
				break;
			}
		}
		ans = (1<<a);
		if((ans^n)>0) cout<<ans<<endl;
		else{
			for(int i=0;i<=31;i++){
				if(!(n&(1<<i))){
					b=i;
					break;
				}
			}
			ans += (1<<b);
			cout<<ans<<endl;
		}
		
	}
}