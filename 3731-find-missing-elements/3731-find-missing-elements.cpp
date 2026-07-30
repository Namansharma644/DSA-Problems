class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int num=nums[0];
        vector<int>ans;

        while(i<n)
        {
           if(nums[i]!=num)
           {
               ans.push_back(num);
               num++;
           }
           else
           {
                num++;
                i++;
           }
        }
        return ans;
    }
};