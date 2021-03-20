#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define ll long long
#define vll vector<ll>
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
 
using namespace std;

int partition(int a[],int start,int end){
	int pivot =a[end];
	int pIndex=start;
	for(int i=start;i<end;i++){
		if(a[i]<=pivot){
			int t=a[i];
			a[i]=a[pIndex];
			a[pIndex]=t;
			++pIndex;
		}
	}
	int t=a[end];
	a[end]=a[pIndex];
	a[pIndex]=t;
	return pIndex;
}
 
void QuickSort(int a[],int start,int end){
 	if(start>=end) return;
 	int pIndex= partition(a,start,end);
 	QuickSort(a,start,pIndex-1);
 	QuickSort(a,pIndex+1,end);
}
 

 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int t;
	cin>>t;
	int a[t];
	for(int i=0;i<t;i++)	cin>>a[i];
	QuickSort(a,0,t-1);
	for(int i=0;i<t;i++) cout<<a[i]<<" ";
	return 0;
}