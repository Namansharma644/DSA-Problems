class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        int rightMax=arr[n-1];
        ans[n-1]=-1;

        for(int i=n-2; i>=0; i--)
        {
            ans[i]=rightMax;
            rightMax=max(rightMax,arr[i]);
        }
        
        return ans;
    }
};