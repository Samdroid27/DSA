#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int maxending = arr[0],minending = arr[0],maxsofar=arr[0];
	for(int i=1;i<arr.size();i++){
		int temp = max({arr[i],arr[i]*maxending,arr[i]*minending});
		minending = min({arr[i],arr[i]*minending,arr[i]*maxending});
		maxending = temp;
		maxsofar = max(maxending,maxsofar);
	}
	return maxsofar;
}
