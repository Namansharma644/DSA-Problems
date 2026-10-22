class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        dp[0]=arr[0];
        
        for(int i=1; i<n; i++)
        {
            int pick=arr[i];
            if(i-2>=0)
            {
                pick+=dp[i-2];
            }
            int notPick=0+dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};