class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        stack<int>s;
        int n=nums2.size();

        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && nums2[s.top()]<nums2[i])
            {
                s.pop();
            }

            m[nums2[i]]= s.empty() ? -1 : nums2[s.top()];

            s.push(i);
        }

        vector<int>ans;

        for(int &a : nums1)
        {
            ans.push_back(m[a]);
        }
        return ans;
    }
};