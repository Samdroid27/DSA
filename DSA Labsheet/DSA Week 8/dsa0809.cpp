#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int findPivot(int a[],int l,int r){
        int mid = 0;
        while(l<=r){
            mid = l + (r-l/2);
            if(mid>0 && a[mid]<a[mid-1]) return mid;
            if(a[mid]>a[0]){
                l = mid+1;
            }else if(a[mid]<a[0]) r = mid-1;
        }
        return mid;
    }
    
    int binSearch(int a[],int l,int r,int key){
        int mid = 0;
        while(l<=r){
            mid = l+ (r-l)/2;
            if(a[mid]==key) return mid;
            else if(a[mid]>key) r = mid-1;
            else l=mid+1;
        }
        return a[mid]==key ? mid : -1;
    }
    
    int search(int A[], int l, int h, int key){
        if(A[0]==key) return 0;
        int ppos = findPivot(A,l,h);
        if(key>A[0]) return binSearch(A,l,ppos-1,key);
        else return binSearch(A,ppos,h,key);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
} 
