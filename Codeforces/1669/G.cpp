#include <bits/stdc++.h>
using namespace std;
 
int mp[31];
 
int main() {
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		string s[n];
		for(int i=0;i<n;i++) cin>>s[i];
		for(int k=0;k<m;k++){
			int i=n-1,j=n-1;
			while(i>=0){
				j=i;
				if(s[i][k]=='.'){
					bool flag=false;
					j--;
					while(j >=0){
						if(s[j][k]=='o'){
							flag = true;
							break;
						}
						if(s[j][k]=='*') break;
						j--;
					}
					if(!flag){
						if(j>=0) swap(s[i][k],s[j][k]);
						else break;
						i--;
					}else{
						i = j = j-1; 
					}
				}
				else i--;
			}
		}
		for(int i=0;i<n;i++) cout<<s[i]<<endl;
		cout<<endl;
	}
}