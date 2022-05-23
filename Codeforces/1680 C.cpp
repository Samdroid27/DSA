#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9;
 
bool binarySearch(int pre[],int suf[],int cnt0,int mid){
	for(int i=0;i<=mid;i++){
		int left = cnt0;
		left -= pre[i];
		left -= suf[mid-i];
		if(left<=mid) return true;
	}
	return false;
}
 
signed main() {
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int cnt0=0;
		for(char c:s) cnt0 += (c=='0');
		int cnt1 = s.size()-cnt0;
		int pre[cnt1+1],suf[cnt1+1];
		int k = 0;
		pre[0]=0;
		for(char c:s){
			if(c=='0') pre[k]++;
			else{
				k++;
				pre[k]=pre[k-1];
			}
		}
		k=0; suf[k]=0;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='0') suf[k]++;
			else{
				k++;
				suf[k]=suf[k-1];
			}
		}
		int cost = cnt1;
		int low = 0,high = cnt1;
		while(low<=high){
			int mid  = low + (high-low)/2;
			if(binarySearch(pre,suf,cnt0,mid)){
				high = mid-1;
				cost = mid;
			}else low = mid+1;
		}
		cout<<cost<<endl;
	}
}