#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    string m;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            m.push_back(a[i++]);
        }else m.push_back(b[j++]);
    }
    while(i<a.size()) m.push_back(a[i++]);
    while(j<b.size()) m.push_back(b[j++]);
    std::cout << m << std::endl;
    return 0;
}