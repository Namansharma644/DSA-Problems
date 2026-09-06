class Solution {
public:
    bool bfs(int v,vector<vector<int>>& graph,vector<int>&color)
    {
        queue<int>q;
        q.push(v);
        color[v]=0;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto &neighbor : graph[node])
            {
                if(color[neighbor]==-1)
                {
                    color[neighbor]=!color[node];
                    q.push(neighbor);
                }
                else if(color[neighbor]!=!color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);

        for(int i=0; i<V; i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,graph,color)==false) return false;
            }
        }
        return true;
    }
};