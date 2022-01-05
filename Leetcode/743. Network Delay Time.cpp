class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        int dist[n];
        for(int i=0;i<n;i++){
            dist[i]=INT_MAX;
        }
        for(vector<int> edge:times){
            edge[0]--,edge[1]--;
            adj[edge[0]].push_back({edge[2],edge[1]});
        }
        k--;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int curr_node = pq.top().second;
            int curr_dist = pq.top().first;
            pq.pop();
            for(pair<int,int> edge:adj[curr_node]){
                if(edge.first+curr_dist<dist[edge.second]){
                    dist[edge.second]=edge.first+curr_dist;
                    pq.push({dist[edge.second],edge.second});
                }
            }
        }
        int ans  = 0;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                ans=-1;
                break;
            }
            ans =max(dist[i],ans);
        }
        return ans;
    }
};