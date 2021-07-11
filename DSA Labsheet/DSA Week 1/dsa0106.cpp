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

void SieveOfEratosthenes(int n,int k)
{	
	int a[10];
	memset(a,0,sizeof(a));
    bool prime[k + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= k; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= k; i += p)
                prime[i] = false;
        }
    }
    for (int p = n; p <= k; p++){
    	if (prime[p]){
        	int num=p;
        	while(num>9){
        		int d=num%10;
        		a[d]++;
        		num/=10;
        	}
        	a[num]++;
        }
    }
    cout<<distance(a,max_element(a,a+10));
    cout<<" "<<*max_element(a,a+10);
        
}
 
i32 main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	IOS;
	int n,k;
	cin>>n>>k;
	SieveOfEratosthenes(n,k);
	return 0;
}