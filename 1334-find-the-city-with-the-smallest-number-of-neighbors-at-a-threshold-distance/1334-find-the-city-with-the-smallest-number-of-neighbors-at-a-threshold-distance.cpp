class Solution {
public:
    void floydWrasall(int n,vector<vector<int>>& SPM)
    {
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    SPM[i][j]=min(SPM[i][j],SPM[i][k]+SPM[k][j]);
                }
            }
        }
    }

    int findResultCity(int n,vector<vector<int>>&SPM,int distanceThreshold)
    {
        int resultCity=-1;
        int leastReachCount=INT_MAX;

        for(int i=0; i<n; i++)
        {
            int countReach=0;
            for(int j=0; j<n; j++)
            {
                if(i!=j && SPM[i][j]<=distanceThreshold)
                {
                    countReach++;
                }
            }

            if(countReach<=leastReachCount)
            {
                resultCity=i;
                leastReachCount=countReach;
            }
        }
        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>SPM(n,vector<int>(n,1e9+7));

        for(auto &it : edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            SPM[u][v]=wt;
            SPM[v][u]=wt;
        }

        floydWrasall(n,SPM);
        return findResultCity(n,SPM,distanceThreshold);
    }
};