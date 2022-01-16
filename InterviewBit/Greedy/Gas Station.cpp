int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int total_left = 0,start = 0, left = 0;
    int n = A.size();
    for(int i=0;i<n;i++){
        total_left += A[i]-B[i];
        if(A[i]+left < B[i]){
            start = i+1;
            left = 0;
        }else{
            left += A[i]-B[i];
        }
    }
    if(total_left < 0) return -1;
    return start;
}