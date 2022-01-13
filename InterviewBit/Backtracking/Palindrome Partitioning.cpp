bool isPalindrome(string &s,int l,int h){
    while(l<h) if(s[l++]!=s[h--]) return false;
    return true;
}

void dfs(vector<vector<string>> &result,vector<string> &curr,string s, int start){
    if(start>=s.size()) result.push_back(curr);
    for(int end=start;end<s.size();end++){
        if(isPalindrome(s,start,end)){
            curr.push_back(s.substr(start,end-start+1));
            dfs(result,curr,s,end+1);
            curr.pop_back();
        }
    }
}


vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> result;
    vector<string> curr;
    dfs(result,curr,A,0);
    return result;
}
