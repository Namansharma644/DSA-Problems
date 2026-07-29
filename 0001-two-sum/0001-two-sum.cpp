class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;

        for(int i=0; i<n; i++)
        {
            int second=target-nums[i];
            if(m.find(second)!=m.end())
            {
                return {m[second],i};
            }
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};