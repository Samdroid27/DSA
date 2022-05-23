// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long int
ll N = 1e9+7;

class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        ll cat[h+1];
        cat[0]=cat[1]=1;
        for(int i=2;i<=h;i++){
            ll a = (cat[i-1]*cat[i-2])%N;
            a = (a*2)%N;
            ll b = (cat[i-1]*cat[i-1])%N;
            cat[i]= (a+b)%N;
        }
        return cat[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends