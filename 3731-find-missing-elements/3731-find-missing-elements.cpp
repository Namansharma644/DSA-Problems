class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        vector<int>ans;

        for(int i=0; i<n; i++)
        {
            s.insert(nums[i]);
        }

        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());

        for(int i=start; i<=end; i++)
        {
            if(s.find(i)==s.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};