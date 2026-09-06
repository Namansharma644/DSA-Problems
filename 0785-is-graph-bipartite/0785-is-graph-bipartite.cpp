class Solution {
public:
    bool dfs(int v,vector<vector<int>>& graph,vector<int>&vis,int color)
    {
        vis[v]=color;

        for(auto &neighbor : graph[v])
        {
            if(vis[neighbor]==-1)
            {
                if(dfs(neighbor,graph,vis,!color)==false) return false;
            }
            else if(vis[neighbor]==color)
            {
                return false;
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
                if(dfs(i,graph,color,0)==false) return false;
            }
        }
        return true;
    }
};