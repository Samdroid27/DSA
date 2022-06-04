int Solution::solve(vector<int> &A, int B) {
    return upper_bound(A.begin(),A.end(),B)-A.begin();
}