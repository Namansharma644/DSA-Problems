class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        while(nums.size()>1)
        {
           sort(nums.begin(), nums.end());

            int n = nums.size();

            int a = nums[n-1];
            int b = nums[n-2];

            nums.pop_back();
            nums.pop_back();

            if(a != b)
                nums.push_back(a - b);
        }
         return nums.empty() ? 0 : nums[0];
    }
};