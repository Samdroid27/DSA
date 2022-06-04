bool isPossible(vector<int> &A,int mid,int B){
    int val=0;
    for(int i:A){
        i>mid ? val+=i-mid:val;
        if(val>=B) return true;
    }
    return false;
}

int Solution::solve(vector<int> &A, int B) {
    int l = 0,r=*max_element(A.begin(),A.end());
    int ans = 0;
    while(l<=r){
        int mid = l+ (r-l)/2;
        if(isPossible(A,mid,B)){
            ans = mid;
            l = mid+1;
        }else r = mid-1;
    }
    return ans;
}
