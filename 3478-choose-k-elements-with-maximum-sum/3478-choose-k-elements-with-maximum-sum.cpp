class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<int>>vec(n);

        for(int i=0;  i<n; i++)
        {
            vec[i]={nums1[i],i,nums2[i]};
        }

        sort(vec.begin(),vec.end());

        long long sum=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<long long>res(n,0);

        for(int i=0; i<n; i++)
        {
            if(i>0 && vec[i-1][0]==vec[i][0])
            {
                long long ans=res[vec[i-1][1]];
                res[vec[i][1]]=ans;
            }
            else
            {
                res[vec[i][1]]=sum;
            }

                sum+=vec[i][2];
                pq.push(vec[i][2]);

                if(pq.size()>k)
                {
                    sum-=pq.top();
                    pq.pop();
                }
        }

        return res;
    }
};