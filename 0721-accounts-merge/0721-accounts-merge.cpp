class Solution {
public:
     class disjointSet{
        vector<int>rank;
        vector<int>parent;
    public:
        disjointSet(int V){
            rank.resize(V+1);
            parent.resize(V+1);
            for(int i=0; i<=V; i++)
            {
                parent[i]=i;
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
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjointSet ds(n);
        unordered_map<string,int>mapMail;

        for(int i=0; i<n; i++)
        {
            auto &it=accounts[i];
            for(int j=1; j<it.size(); j++)
            {
                if(mapMail.find(it[j])==mapMail.end())
                {
                    mapMail[it[j]]=i;
                }
                else
                {
                    ds.unionByRank(i,mapMail[it[j]]);
                }
            }
        }

        vector<vector<string>>mails(n);
        for(auto &it : mapMail)
        {
            string mail=it.first;
            int node=ds.findUlParent(it.second);

            mails[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0; i<n; i++)
        {
            if(mails[i].size()==0) continue;
            sort(mails[i].begin(),mails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it : mails[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};