int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = n-1;
    int l = 0,r=A.size()-1;
    while(l<=r){
        int mid = l+((r-l)/2);
        if(mid+1<n){
            if(A[mid+1]<A[mid]){
                i=mid;
                r=mid-1;
            }else l=mid+1;
        }else break;
    }
    int ans = -1;
    l=0,r=i;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(A[mid]==B){
            ans=mid;
            break;
        }else if(A[mid]<B) l=mid+1;
        else r= mid-1;
    }
    if(ans==-1){
        l=i+1,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(A[mid]==B){
                ans=mid;
                break;
            }else if(A[mid]<B) r=mid-1;
            else l= mid+1;
        }
    }
    return ans;
}
