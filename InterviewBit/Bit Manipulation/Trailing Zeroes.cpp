int Solution::solve(int A) {
    for(int i=0;i<=31;i++){
        if(A&(1<<i)) return i;
    }
}