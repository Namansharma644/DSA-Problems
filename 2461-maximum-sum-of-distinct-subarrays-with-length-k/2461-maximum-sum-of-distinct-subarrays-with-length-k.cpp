class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxSum=0;
        long long sum=0;
        unordered_set<int>s;

        int i=0,j=0;

        while(j<n)
        {
            while(s.count(nums[j]))
            {
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            s.insert(nums[j]);

            while(i<n && ((j-i+1)>k))
            {
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }

            if((j-i+1)==k)
            {
                maxSum=max(maxSum,sum);
            }

            j++;
        }
        return maxSum;
    }
};