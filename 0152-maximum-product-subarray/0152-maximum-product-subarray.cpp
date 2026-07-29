class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int sufix=1;
        int prefix=1;
        int maxProd=INT_MIN;

        for(int i=0; i<n; i++)
        {
            if(prefix==0) prefix=1;
            if(sufix==0) sufix=1;

            prefix*=nums[i];
            sufix*=nums[n-i-1];
            
            maxProd=max(maxProd,max(sufix,prefix));
        }
        return maxProd;
    }
};