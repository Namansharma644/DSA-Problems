class Solution {
public:
     int findPivot(vector<int>&nums,int n)
    {
        
        int l=0,r=n-1;
        while(l<r && nums[l]==nums[l+1])
        {
            l++;
        }

        while(l<r && nums[r]==nums[r-1])
        {
            r--;
        }

        while(l<r)
        {
            int mid=l+(r-l)/2;

            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return r;
    }

    bool binarySearch(int l,int r,vector<int>& nums, int target)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(nums[mid]==target)
            {
                return true;
            }

            if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return false;
    }
    bool search(vector<int>& nums, int target) {
         int n=nums.size();
        int pivotIdx=findPivot(nums,n);
        if(binarySearch(0,pivotIdx-1,nums,target)){
            return true;
        }

        return binarySearch(pivotIdx,n-1,nums,target);
    }
};