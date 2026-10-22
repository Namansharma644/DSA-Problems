class Solution {
public:
    int helper(int n,vector<int>& arr,vector<int>&dp)
    {
        if(n==0) return arr[0];
        if(n<1) return 0;
        if(dp[n]!=-1) return dp[n];
        
        int pick=arr[n]+helper(n-2,arr,dp);
        int notPick=0+helper(n-1,arr,dp);
        
        return dp[n]=max(pick,notPick);
    }
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(n-1,arr,dp);
    }
};