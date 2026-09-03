class Solution {
public:
    void dfs(int v,vector<bool>&vis,vector<vector<int>>& isConnected)
    {
        vis[v]=true;

        for(int i=0; i<isConnected.size(); i++)
        {
            if(isConnected[v][i]==1 && vis[i]==false)
            {
                dfs(i,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);

        int count=0;

        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count;
    }
};