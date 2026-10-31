class Solution {
public:
    bool isSubsetSum(vector<int>arr, int target){
       int n=arr.size();
       vector<vector<bool>>dp(n,vector<bool>(target+1,false));
 
       for(int i=0; i<n; i++)
       {
          dp[i][0]=true;
       }
    
      if(arr[0]<=target) dp[0][arr[0]] = true;
 
       for(int i=1; i<n; i++)
       {
            for(int t=1; t<=target; t++)
            {
                bool pick=false;
                bool notPick=false;
 
                if(arr[i]<=t)
                {
                    pick=dp[i-1][t-arr[i]];
                }
 
                
                notPick=dp[i-1][t];
                dp[i][t]=(pick || notPick);
            }
       }
       return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;

        for(int i=0; i<n; i++)
        {
            totalSum+=nums[i];
        }

        if(totalSum % 2) return false;
        int target=totalSum/2;
       
        return isSubsetSum(nums,target);
    }
};