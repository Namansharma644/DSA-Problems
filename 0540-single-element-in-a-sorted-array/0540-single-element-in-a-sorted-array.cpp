class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;

        while(l<r)
        {
            int mid=l+(r-l)/2;

            bool isEven;

            (r-mid)%2==0 ? isEven=true : isEven=false;

            if(nums[mid]==nums[mid+1])
            {
                if(isEven)
                {
                   l=mid+2;
                }
                else
                {
                    r=mid-1;
                }
            }
            else
            {
                if(isEven)
                {
                    r=mid;
                }
                else
                {
                     l=mid+1;
                }
            }
        }
        return nums[r];
    }
};