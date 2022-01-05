class Solution {
public:
    vector<pair<double,int>> adj[10005];
    double dist[10005];
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        for(int i=0;i<1005;i++) dist[i]=0;
        dist[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            int curr_node = pq.top().second;
            double curr_prob = pq.top().first;
            pq.pop();
            for(pair<double,int> edge:adj[curr_node]){
                if((double)edge.first*curr_prob > dist[edge.second]){
                    dist[edge.second]=(double) edge.first*curr_prob;
                    pq.push({dist[edge.second],edge.second});
                }
            }            
        }
        return dist[end];
    }
};
