class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int res=0;
        int currSum=0;
        unordered_map<int,int>m;
        m[0]=1;

        for(int &num : nums)
        {
            currSum+=num;

            if(m.find(currSum-goal)!=m.end())
            {
                res+=m[currSum-goal];
            }

            m[currSum]++;
        }
        return res;
    }
};