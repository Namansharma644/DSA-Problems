class Solution {
public:
    int count(vector<int> &arr, int mid)
    {
        int studentCount=1,pages=0;
        
        for(int &a : arr)
        {
            if(pages+a<=mid)
            {
                pages+=a;
            }
            else
            {
                studentCount++;
                pages=a;
            }
        }
        return studentCount;
    }
    int splitArray(vector<int>& nums, int k) {
         if(k > nums.size()) return -1;
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);
        int ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int studentCount=count(nums,mid);
            
            if(studentCount>k)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};