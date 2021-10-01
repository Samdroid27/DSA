#include<bits/stdc++.h>
#include<algorithm>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pq priority_queue
#define all(v) v.begin(),v.end()
#define pb push_back
#define int long long
#define uom unordered_map
#define uos unordered_set
#define vi vector<int>
#define vvi(v,n,m) vector<vi> v( n , vi (m))
#define sz(x) x.size()
#define i32 int32_t
#define sep " "
 
using namespace std;

int merge(vi &a,int l,int m, int r){
	int inv = 0;
	int n1 = m-l+1;
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
			inv += n1-i;
			//a[i],a[i+1]...a[n-1]>a[j]
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
	return inv;
}


int mergeSortInv(vi &a,int l,int r){
	int inv=0;
	if(l<r){
		int mid=l+ ((r-l)/2);
		inv+=mergeSortInv(a,l,mid);
		inv+=mergeSortInv(a,mid+1,r);
		inv+=merge(a,l,mid,r);
	}
	return inv;
}

 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<mergeSortInv(a,0,n-1)<<endl;
	return 0;
}
