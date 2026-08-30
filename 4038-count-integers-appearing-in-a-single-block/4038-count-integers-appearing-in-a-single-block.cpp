class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>vis;
        unordered_set<int>vaild;

        for(int i=0; i<n; i++)
        {
            if(vis.find(nums[i])!=vis.end())
            {
                vaild.erase(nums[i]);
                
            }
            else
            {
                vis.insert(nums[i]);
                while(i+1<n && nums[i]==nums[i+1]) i++;
                vaild.insert(nums[i]);
            }
           
        }
        return vaild.size();
   }
};