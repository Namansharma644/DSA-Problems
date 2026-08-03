class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        vector<int>ans(n,0);

        for(int i=0; i<n; i++)
        {
            (nums[i]>0) ? pos.push_back(nums[i]) : neg.push_back(nums[i]);
        }

        int i=0;
        int j=0;
        int k=0;
        bool isAlt=true;

        while(i<pos.size() || j<neg.size())
        {
            if(isAlt)
            {
                ans[k]=pos[i];
                i++;
            }
            else
            {
                ans[k]=neg[j];
                j++;
            }
            isAlt=!isAlt;
            k++;
        }
        return ans;
    }
};