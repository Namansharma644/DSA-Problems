class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>temp;

        for(int i=0; i<n; i++)
        {
            temp.push_back({arr[i],i});
        }

        sort(temp.begin(),temp.end());

        vector<int>res(n,0);
        int rank=0;
        for(int i=0; i<n; i++)
        {
            if(i==0 || temp[i].first!=temp[i-1].first)
            {
                rank++;
            }
            int idx=temp[i].second;
            res[idx]=rank;
        }
        return res;
    }
};