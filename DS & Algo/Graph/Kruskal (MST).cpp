#include <bits/stdc++.h>
#define edge pair<int,pair<int,int>>
using namespace std;

std::vector<int> par;

int find(int a){
    if(par[a]==-1) return a;
    return par[a]=find(par[a]);
}

int main() {
	int n,e;
	cin>>n>>e;
	par.resize(n+1,-1);
	priority_queue<edge,vector<edge>, greater<edge>> pq;
	for(int i=0;i<e;i++){
	    int a,b,w;
	    cin>>a>>b>>w;
	    pq.push({w,{a,b}});
	}
	int sum = 0;
	while(pq.size()>0){
	    edge i=pq.top();
	    pq.pop();
	    int u = find(i.second.first);
	    int v = find(i.second.second);
	    if(u!=v){
	        par[u]=v;
	        sum+=i.first;
	        
	    }
	}
	cout<<sum<<endl;
	return 0;
}
