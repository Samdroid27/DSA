#include<bits/stdc++.h>
using namespace std;
 
 void baab(int tot,int t,int s,int tp){
 	if(t==0){
 		if(tp==0){
 			cout<<"NO"<<endl;
 		}
 		else return;
 	}
 	else{
 		char c;
 		cin>>c;
 		if(s==3){
 			if(c=='b'){
 				if(tp>0) cout<<tot-t-2<<" ";
 				else	cout<<"YES "<<tot-t-2<<" ";
 				baab(tot,t-1,1,tp+1);
 			}
 			else baab(tot,t-1,0,tp);
 		}
 		else if(s==2){
 			if(c=='a') baab(tot,t-1,3,tp);
 			else baab(tot,t-1,1,tp);
 		}
 		else if(s==1){
 			if(c=='a') baab(tot,t-1,2,tp);
 			else baab(tot,t-1,1,tp);
 		}
 		else if(s==0){
 			if(c=='b') baab(tot,t-1,1,tp);
 			else baab(tot,t-1,0,tp);
 		}
 	}
 }
 
 int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;
	cin>>t;
	baab(t,t,0,0);
	return 0;
}