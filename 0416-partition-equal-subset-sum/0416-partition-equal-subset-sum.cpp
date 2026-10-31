class Solution {
public:
    bool isSubsetSum(vector<int>arr, int target){
       int n=arr.size();
       vector<bool>prev(target+1,false);
       prev[0]=true;
       if(arr[0]<=target) prev[arr[0]]=true;
    
 
       for(int i=1; i<n; i++)
       {
            vector<bool>curr(target+1,false);
            curr[0]=true;
            for(int t=1; t<=target; t++)
            {
                bool pick=false;
                bool notPick=false;
 
                if(arr[i]<=t)
                {
                    pick=prev[t-arr[i]];
                }
 
                
                notPick=prev[t];
                curr[t]=(pick || notPick);
            }
            prev=curr;
       }
       return prev[target];
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