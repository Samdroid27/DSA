/*
Given an array having both positive and negative integers. The task is to compute the length of
the largest contiguous subarray with sum 0.
Input
The first line contains one integer N, the sizes of array (1 <= N <= 2 x 1e5). The next line contains
contains N integers each integer representing ai (-1e9 <= ai <=1e9).
Output
Output one integer, the length of the largest such subarray. If no such subarray exists, print 0.
input
8
15 -2 2 -8 1 7 10 23
output
5
explanation
The largest subarray is: -2 2 -8 1 7
10
*/


int maxLen(int A[], int n)
{
    map<int,int> mp;
    int s=0;
    int max_length =0;
    for(int i=0;i<n;i++){
        s+=A[i];
        if(A[i]==0 && max_length == 0) max_length = 1;
        if(s==0) max_length = i+1;
        if(mp.find(s)!=mp.end()) max_length = max(max_length,i-mp[s]);
        else mp[s]=i;
    }
    return max_length;
}