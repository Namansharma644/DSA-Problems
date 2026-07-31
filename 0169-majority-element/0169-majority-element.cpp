class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int maj=nums[0];

        for(int i=1; i<n; i++)
        {
            if(count==0)
            {
                maj=nums[i];
                count=1;
                continue;
            }

            if(maj==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return maj;
    }
};