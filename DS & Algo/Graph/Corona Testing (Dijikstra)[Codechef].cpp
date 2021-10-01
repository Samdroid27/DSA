/*
Codechef Problem Code : https://www.codechef.com/problems/CORONA
There are N cities (numbered from 1 to N) and M bidirectional roads. 
The ith of these roads connects the cities Ai and Bi and has a length of Di Km.

There are only K cities that have a hospital for corona testing. 
The cost of corona testing may be different in different cities. 
For each city, we want to know the minimum cost that needs to be spent to test a corona sample. 
If city you are in contains a hospital and you choose to test in that hospital itself, then the cost incurred is the cost of corona test in that hospital. 
Otherwise, if you choose to test in a hospital in another city, then an additional transportation cost is also incurred (Assuming Rs.1 per Km).

So from a city i, if you choose to send a sample to city j, then the total cost incurred will be Cj+D(i,j). 
Here Cj denotes the cost of corona testing in a hospital situated in city j and D(i,j) denotes the minimum distance between city i and j via some road network.

Output the minimum money that should be spent by a person in each of the N cities for testing a corona sample.

It is guaranteed that there is a path from every city to every other city. Also, there is at most one road between any pair of cities (i.e. no multiple edges). 
There are no roads from one city to itself (i.e. no self-loops).

Note: Since the inputs and outputs are large, prefer using fast input-output methods.

Input Format
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
Each testcase contains K+M+1 lines of input.
The first line of each test case contains three space-separated integers N,M,K.
K lines follow. For each valid i, the ith of these lines contains two space-separated integers xi,Ci which denotes that there is a hospital in the xthi city and the cost of corona testing in that hospital is Ci. 
There is at most one hospital in a city i.e. all xi-s are distinct.
Next M lines follow. For each valid i, the ith of these lines contains three space-separated integers Ai,Bi,Di, which denotes that there is a bidirectional road between City Ai and City Bi of length Di Km.
Output Format
For each test case, print a single line containing N space-separated integers, where the ith integer denotes the minimum cost of corona testing if you are in the ith city.

Constraints
1<=T<=4000
2<=N<=2.105
1<=M<=4.105
1<=K<=N
1<=i,Ai,Bi<=N for each valid i
1<=Ci<=109 for each valid i
1<=Di<=109 for each valid i
Sum of N over all test cases does not exceed 2.105
Sum of M over all test cases does not exceed 4.105
All xi-s in a testcase are distinct.
It is guaranteed that there is a path from every city to every other city.
It is guaranteed that there are no self loops and multiple edges.
Sample Input 1 
2
3 2 2
1 5
2 10
1 2 6
2 3 9
3 2 2
1 5
2 10
1 2 1
2 3 9
Sample Output 1 
5 10 19 
5 6 15 
Explanation
Test case 1: The hospitals are situated at cities 1 and 2 with their costs being 5 and 10 respectively.
For city 1 it is optimal to test the sample in its own hospital bearing a total cost of 5. 
For city 2 it is again optimal to test the sample in its own hospital bearing a total cost of 10. 
For city 3 it is optimal to test the sample in the hospital at city 2 which incurs the traveling cost of 9 and hospital cost of 10, so the total cost is 10+9=19.

Test case 2: For city 2, it is optimal to test the sample in hospital at city 1 which incurs a traveling cost of 1 and hospital cost of 5, so the total cost is 1+5=6.
*/


#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;
vector<vector<pii> >  adj;
vector<pii> hospitals;
vector<int> ans;

void dijikstra(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(auto h:hospitals){
        ans[h.first]=h.second;
        pq.push({h.second,h.first});
    }
    while(!pq.empty()){
        pii node = pq.top();
        pq.pop();
        for(auto &e:adj[node.second]){
            int new_node = e.first;
            int wt = e.second;
            if(ans[new_node]>ans[node.second]+wt){
                ans[new_node]=ans[node.second]+wt;
                pq.push({ans[new_node],new_node});
            }
        }
    }
}


signed main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
	    cin>>n>>m>>k;
	    adj = vector<vector<pii>>(n+1);
	    ans.clear();
	    hospitals.clear();
	    ans.resize(n+1,1e15);
	    for(int i=0;i<k;i++){
	        int x,c;
	        cin>>x>>c;
	        hospitals.push_back({x,c});
	    }
	    for(int i=0;i<m;i++){
	        int u,v,w;
	        cin>>u>>v>>w;
	        adj[u].push_back({v,w});
	        adj[v].push_back({u,w});
	    }
	    dijikstra();
	    for(int i=1;i<=n;i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
    }
	
	return 0;
}
