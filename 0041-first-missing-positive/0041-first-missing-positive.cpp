class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool contain1=false;

        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
            {
                contain1=true;
            }

            if(nums[i]<=0 || nums[i]>n)
            {
                nums[i]=1;
            }
        }

        if(!contain1)
        {
           return 1;
        }

        for(int i=0; i<n; i++)
        {
            int idx=abs(nums[i])-1;
            nums[idx]=-abs(nums[idx]);
        }

        for(int i=0; i<n; i++)
        {
            if(nums[i]>0){
                return i+1;
            }
        }

        return n+1;
    }
};