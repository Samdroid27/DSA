int Solution::numSetBits(unsigned int A) {
    int ans =0;
    for(int i=31;i>=0;i--){
        if(A&(1<<i)) ans++;
    }
    return ans;
}