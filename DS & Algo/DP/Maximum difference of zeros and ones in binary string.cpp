class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int ans=-1,curr = 0;
	    for(int i=0;i<S.size();i++){
	        if(curr<0) curr= 0;
	        if(S[i]=='0') curr++;
	        if(S[i]=='1') curr--;
	        ans = max(curr,ans);
	    }
	    return ans;
	}
};