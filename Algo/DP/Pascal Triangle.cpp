//Given an integer numRows, return the first numRows of Pascal's triangle.

class Solution {
public:
    vector<vector<int> > pascal;
    
    void solve(int n){
        if(n==0) return;
        solve(n-1);
        vector<int> v(n);
        v[0]=1;
        if(n==1){
            pascal.push_back(v);
            return;
        }
        v[n-1]=1;
        for(int i=1;i<n-1;i++){
            v[i]=pascal[n-2][i-1]+pascal[n-2][i];
        }
        pascal.push_back(v);
        return;
        
    }
    
    
    vector<vector<int>> generate(int numRows) {
        solve(numRows);
        return pascal;
    }
};