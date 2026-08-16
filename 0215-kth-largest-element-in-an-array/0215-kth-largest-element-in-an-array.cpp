class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      int n=nums.size();
      int i=0;
      priority_queue<int,vector<int>,greater<int>>pq;

      while(i<n)
      {
        pq.push(nums[i]);

        if(pq.size()>k)
        {
            pq.pop();
        }
        i++;
      }
      return pq.top();
    }
};