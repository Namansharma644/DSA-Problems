class Solution {
public:
    typedef pair<long long,int>P;
    int M=1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it : roads)
        {
            int u=it[0];
            int v=it[1];
            int t=it[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long>dis(n, LLONG_MAX);
        vector<int>paths(n,0);
        dis[0]=0;
        paths[0]=1;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,0});

        while(!pq.empty())
        {
            long long cost=pq.top().first;
            int curr=pq.top().second;
            pq.pop();

            for(auto &it : adj[curr])
            {
                int neighbor=it.first;
                int time=it.second;

                if(dis[neighbor]>cost+time)
                {
                    dis[neighbor]=cost+time;
                    pq.push({cost+time,neighbor});
                    paths[neighbor]=paths[curr];
                }
                else if(cost+time == dis[neighbor])
                {
                    paths[neighbor]=(paths[neighbor]+paths[curr]) % M;
                }
            }
        }
        return paths[n-1] % M;
    }
};