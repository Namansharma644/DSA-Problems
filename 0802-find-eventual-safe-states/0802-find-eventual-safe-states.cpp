class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++)
        {
            for(auto &val : graph[i])
            {
                adj[val].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>safeNodes;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            safeNodes.push_back(curr);

            for(auto &val : adj[curr])
            {
                indegree[val]--;
                if(indegree[val]==0) q.push(val);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};