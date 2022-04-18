class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool check[s.size()+1];
        memset(check,false,sizeof(check));
        check[0]=true;
        for(int i=1;i<=s.size();i++){
            for(string word:wordDict){
                if(word.size()<=i){
                    if(check[i-word.size()]){
                        if(s.substr(i-word.size(),word.size())==word){
                            check[i]=true;
                            break;
                        }
                    }
                }
            }
        }
        return check[s.size()];
    }
};