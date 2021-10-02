/*
Hackerrank Question link: https://www.hackerrank.com/challenges/contacts/problem

We're going to make our own Contacts application! The application must perform two types of operations:

1. add name, where name is a string denoting a contact name. 
This must store name as a new contact in the application.
2. find partial, where partial is a string denoting a partial name to search the application for. 
It must count the number of contacts starting with partial and print the count on a new line.
Given  sequential add and find operations, perform each operation in order.

Example
Operations are requested as follows:

add ed
add eddie
add edward
find ed
add edwina
find edw
find a


Three add operations include the names 'ed', 'eddie', and 'edward'. 
Next,  ed matches all 3 names. Note that it matches and counts the entire name 'ed'. 
Next, add 'edwina' and then find 'edw'. 2 names match: 'edward' and 'edwina'. 
In the final operation, there are 0 names that start with 'a'. Return the array [3,2,0].

Constraints
1<=n<=1e5
1<=|add|,|partial|<=21
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

class Trie{
    public:
        map<char,Trie*> child;
        int cnt=0;
};

 void insert(Trie* root,string s){
     int l = s.size();
     for(int i=0;i<l;i++){
         if(!root->child[s[i]]){
             root->child[s[i]]=new Trie();
         }
         root = root->child[s[i]];
         root->cnt++;
     }
 }

 
 int countWords(Trie* root,string find){
     bool flag = true;
     for(char c:find){
         if(!root->child[c]){
             flag = false;
             break;
         }root= root->child[c];
     }
     if(!flag) return 0;
     return root->cnt;
     
 }

vector<int> contacts(vector<vector<string>> queries) {
    Trie* root = new Trie();
    vector<int> ans;
    for(vector<string> q:queries){
        if(q[0]=="add") insert(root,q[1]);
        else{
            ans.push_back(countWords(root,q[1]));
        }
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<vector<string>> queries;
    for(int i=0;i<n;i++){
        vector<string> q;
        string a,b;
        cin>>a>>b;
        q.push_back(a);
        q.push_back(b);
        queries.push_back(q);
    }
    vector<int> ans = contacts(queries);
    for(int i:ans){
        cout<<i<<endl;
    }
}
