class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &it : times)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dis[k]=0;

        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it : adj[node])
            {
                int neighbor=it.first;
                int cost=it.second;

                if(d+cost < dis[neighbor])
                {
                    dis[neighbor]=d+cost;
                    pq.push({d+cost,neighbor});
                }
            }
        }

        int ans=INT_MIN;

        for(int i=1; i<=n; i++)
        {
           ans=max(ans,dis[i]);
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};