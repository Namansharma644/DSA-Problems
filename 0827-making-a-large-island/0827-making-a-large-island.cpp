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

    bool isVaild(int row,int col,int n)
    {
        return row>=0 && row<n && col>=0 && col<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointSet ds(n*n);

        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col]==0) continue;
                vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
                for(auto &dir : directions)
                {
                    int newRow=row+dir[0];
                    int newCol=col+dir[1];
                    int nodeNum=row*n+col;
                    int adjNum=newRow*n+newCol;

                    if(isVaild(newRow,newCol,n) && grid[newRow][newCol]==1)
                    {
                        ds.unionBySize(nodeNum,adjNum);
                    }
                }
            }
        }

        int ans=0;
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col]==1) continue;
                vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
                unordered_set<int>s;
                for(auto &dir : directions)
                {
                    int newRow=row+dir[0];
                    int newCol=col+dir[1];
                    int adjNum=newRow*n+newCol;
                    
                    if(isVaild(newRow,newCol,n))
                    {
                       if(grid[newRow][newCol]==1)
                       {
                          s.insert(ds.findUlParent(adjNum));
                       }
                    }
                }

                int totalSize=0;
                for(auto &it : s)
                {
                    totalSize+=ds.size[it];
                }
                ans=max(ans,totalSize+1);
            }
        }
            for(int cellNo=0; cellNo<=n*n; cellNo++)
            {
                ans=max(ans,ds.size[ds.findUlParent(cellNo)]);
            }
            return ans;
    }
};