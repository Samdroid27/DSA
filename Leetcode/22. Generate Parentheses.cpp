class Solution {
public:
    void gen(int n,string &s,vector<string> &ans,int open,int close){
        if(open==close && open==n){
            ans.push_back(s);
            return;
        }
        if(close>open || open>n) return;
        if(close<open){
            s.push_back(')');
            gen(n,s,ans,open,close+1);
            s.pop_back();
        }
        if(open<n){
            s.push_back('(');
            gen(n,s,ans,open+1,close);
            s.pop_back();
        }
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        gen(n,temp,ans,0,0);
        return ans;
    }
};