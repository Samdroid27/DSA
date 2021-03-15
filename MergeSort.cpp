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

int merge(int a[],int l,int m,int r){
	int n1 = m-l +1;
	int n2 = r-m;

	int L[n1], R[n2];

	for(int i=0;i<n1;i++) L[i]= a[l+i];
	for(int i=0;i<n2;i++) R[i]= a[m+1+i];

	int i=0,j=0,k=l;

	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]= R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}

	while(j<n2){
		a[k]= R[j];
		j++;
		k++;
	}
}
 
void mergeSort(int a[],int l,int r){
 	if(l>=r) return;
 	int m = l+ (r-l)/2;
 	mergeSort(a,l,m);
 	mergeSort(a,m+1,r);
 	merge(a,l,m,r);
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
	mergeSort(a,0,t-1);
	for(int i=0;i<t;i++) cout<<a[i]<<" ";
	return 0;
}