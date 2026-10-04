class Solution {
public:
     class disjointSet{
    public:
        vector<int>rank;
        vector<int>parent;
        vector<int>size;
        disjointSet(int V){
            rank.resize(V+1);
            parent.resize(V+1);
            size.resize(V+1);
            for(int i=0; i<=V; i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findUlParent(int v)
        {
            if(parent[v]==v)
            {
                return v;
            }
            return parent[v]=findUlParent(parent[v]);
        }
        
        void unionByRank(int u,int v)
        {
            int ultParentU=findUlParent(u);
            int ultParentV=findUlParent(v);
            if(ultParentU==ultParentV) return;
            
            if(rank[ultParentU]<rank[ultParentV]){
                parent[ultParentU]=ultParentV;
            }
            else if(rank[ultParentU]>rank[ultParentV])
            {
                parent[ultParentV]=ultParentU;
            }
            else
            {
                parent[ultParentV]=ultParentU;
                rank[ultParentU]++;
            }
        }

        void unionBySize(int u,int v)
        {
            int ultParentU=findUlParent(u);
            int ultParentV=findUlParent(v);
            if(ultParentU==ultParentV) return;

            if(size[ultParentU]<size[ultParentV])
            {
                parent[ultParentU]=ultParentV;
                size[ultParentV]+=size[ultParentU];
            }
            else
            {
                parent[ultParentV]=ultParentU;
                size[ultParentU]+=size[ultParentV];
            }
        }
    };
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        disjointSet ds(n);
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    ds.unionByRank(i,j);
                }
            }
        }

        int groups=0;
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i]==i)
            {
                groups++;
            }
        }
        return n-groups;
    }
};