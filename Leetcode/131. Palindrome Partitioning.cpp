class Solution {
public:
    bool isPalindrome(string &s,int l,int h){
        while(l<h){
            if(s[l++]!=s[h--]) return false;
        }
        return true;
    }
    
    void dfs(int start,string &s,vector<string> &curr,vector<vector<string>> &result){
        if(start>=s.size()) result.push_back(curr);
        for(int end=start;end<s.size();end++){
            if(isPalindrome(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                dfs(end+1,s,curr,result);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        dfs(0,s,curr,result);
        return result;
    }
};