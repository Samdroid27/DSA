int Solution::solve(vector<int> &A, int B) {
    int pre[A.size()+1],suf[A.size()+1];
    int sm = 0; pre[0]=0,suf[A.size()]=0;
    for(int i=0;i<A.size();i++){
        pre[i+1] = pre[i]+A[i];
    }
    for(int j = A.size()-1;j>=0;j--){
        suf[j]= suf[j+1]+A[j];
    }
    int mx = INT_MIN;
    for(int i=0;i<=B;i++){
        mx = max(mx,pre[i]+suf[A.size()-B+i]);
    }
    return mx;
}