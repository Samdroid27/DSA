#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &x,int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int inv =0;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=x[l+i];
    for(int i=0;i<n2;i++) R[i]=x[m+i+1];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) x[k++]=L[i++];
        else{
            x[k++]=R[j++];
            inv += n1-i;
        }
    }
    while(i<n1) x[k++]=L[i++];
    while(j<n2) x[k++]=R[j++];
    return inv;
}

int mergeSortCountInv(vector<int> &x,int l,int r){
    int inv =0;
    if(l<r){
        int mid = l+ (r-l)/2;
        inv += mergeSortCountInv(x,l,mid);
        inv += mergeSortCountInv(x,mid+1,r);
        inv += merge(x,l,mid,r);
    }
    return inv;
}

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    std::cout << mergeSortCountInv(x,0,n-1) << std::endl;
    return 0;
}
