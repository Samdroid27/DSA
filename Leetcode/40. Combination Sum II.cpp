class Solution {
public:
    
    void backtrack(vector<int>& c,int i,vector<int>& temp,vector<vector<int>>& ans,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int iter=i;iter<c.size();iter++){
            if(iter>i && c[iter]==c[iter-1]) continue;
            temp.push_back(c[iter]);
            backtrack(c,iter+1,temp,ans,target-c[iter]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        backtrack(candidates,0,temp,ans,target);
        return ans;
    }
};