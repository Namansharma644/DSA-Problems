class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
      

        for(int i=0; i<n-1; i++)
        {
            int rightMax=0;
            for(int j=i+1; j<n; j++)
            {
               rightMax=max(rightMax,arr[j]);
            }
            ans[i]=rightMax;
        }

        ans[n-1]=-1;
        return ans;
    }
};