class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        unordered_map<int,vector<int>> adj;   // map of stop -> vector<routes_having_that_stop>
        set<int> visited_route;
        set<int> visited_stop;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int stop:routes[i]){
                adj[stop].push_back(i);
            }
        }
        
        queue<int> q;
        q.push(source);

        // multisource bfs on all routes which have Source stop
        // A level in each traversal denote change in route
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int cur_stop = q.front();
                q.pop();

                if(cur_stop == target) return ans;

                for(int route: adj[cur_stop]){
                    if(visited_route.find(route) != visited_route.end()) continue;
                    visited_route.insert(route);
                    for(int stop: routes[route]){
                        if(visited_stop.find(stop) != visited_stop.end()) continue;
                        visited_stop.insert(stop);
                        q.push(stop);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};