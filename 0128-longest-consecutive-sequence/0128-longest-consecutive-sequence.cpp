class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int smallest=INT_MIN;
        int largest=1;
        int count=1;

        for(int i=0; i<n; i++)
        {
            int x=nums[i];
            if(x-1==smallest)
            {
                count++;
                smallest=nums[i];
            }
            else if(nums[i]!=smallest)
            {
                count=1;
                smallest=nums[i];
            }

            largest=max(largest,count);
        }
        return largest;
    }
};