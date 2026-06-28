class Solution {
public:
    int isPossible(vector<int>& nums, int mid)
    {
        int sum=0;
        for(int &a : nums){
            sum+=ceil((double)a/(double)mid);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(isPossible(nums,mid)<=threshold)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return ans;
    }
};