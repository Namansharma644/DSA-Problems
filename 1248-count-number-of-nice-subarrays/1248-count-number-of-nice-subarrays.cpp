class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n=nums.size();
        int res=0;
        int currOdd=0;
        int i=0,j=0;
        int currEven=0;

        while(j<n)
        {
            currOdd+=(nums[j]%2);

            while(i<j && (nums[i]%2==0 || currOdd>k))
            {
                 (nums[i]%2==0) ? currEven++ : currEven=0;
                 currOdd-=(nums[i]%2);
                 i++;
            }

            if(currOdd==k)
            {
                res+=(1+currEven);
            }

            j++;
        }
        return res;
    }
};