#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e9+7;

int findSum(string a){
    string temp = "";
    int sum=0;
    for(char c:a){
        if(isdigit(c)) temp+=c;
        else{
            sum+=(atoll(temp.c_str()));
            temp="";
        }
    }
    sum+=(atoi(temp.c_str()));
    return sum;
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<int> wealth;
    while(n--){
        string a;
        cin>>a;
        wealth.push_back(findSum(a));
    }
    sort(wealth.rbegin(),wealth.rend());
    int ans = 0,i=0;
    while(k-- && i<wealth.size()){
        ans+=wealth[i++];
    }
    std::cout << ans%N << std::endl;
    return 0;
}