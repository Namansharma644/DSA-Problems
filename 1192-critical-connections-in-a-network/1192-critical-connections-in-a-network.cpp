class Solution {
public:
    int timer=0;
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,vector<int>&time,vector<int>&low,vector<vector<int>>&ans)
    {
        vis[node]=1;
        timer++;
        time[node]=timer;
        low[node]=timer;

        for(auto &it : adj[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis,time,low,ans);
                low[node]=min(low[it],low[node]);

                if(low[it]>time[node])
                {
                    ans.push_back({it,node});
                }
            }
            else
            {
                low[node]=min(low[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>time(n,0);
        vector<int>low(n,0);
        vector<int>vis(n,0);
        vector<vector<int>>ans;
        dfs(0,-1,adj,vis,time,low,ans);
        return ans;
    }
};