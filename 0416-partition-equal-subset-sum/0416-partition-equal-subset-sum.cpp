class Solution {
public:
    bool helper(int i,int target,vector<int>&arr,int n,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(i==0) return (arr[0]==target);
        if(dp[i][target]!=-1) return dp[i][target];
 
        bool pick=false;
        if(arr[i]<=target){
            pick=helper(i-1,target-arr[i],arr,n,dp);
        }
        if(pick) return dp[i][target]=true;
        bool notPick=helper(i-1,target,arr,n,dp);
        if(notPick) return dp[i][target]=true;
 
        return dp[i][target]=(pick || notPick);
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
       
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(n-1,target,nums,n,dp);
    }
};