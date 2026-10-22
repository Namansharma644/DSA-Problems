class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        
        for(int i=1; i<n; i++)
        {
            int pick=arr[i];
            if(i-2>=0)
            {
                pick+=prev2;
            }
            int notPick=prev;
            int curri=max(pick,notPick);
            
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};