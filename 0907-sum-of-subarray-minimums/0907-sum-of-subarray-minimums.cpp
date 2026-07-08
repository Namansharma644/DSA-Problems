class Solution {
public:
    vector<int> findLeftSmaller(vector<int>& arr,int n)
    {
        vector<int>ans(n);
        stack<int>s;

        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                s.pop();
            }

            ans[i]=(s.empty()) ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> findRightSmaller(vector<int>& arr,int n)
    {
        vector<int>ans(n);
        stack<int>s;

        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }

            ans[i]=(s.empty()) ? n : s.top();
            s.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left=findLeftSmaller(arr,n);
        vector<int>right=findRightSmaller(arr,n);

        long long sum=0;
        int M=1e9+7;

        for(int i=0; i<n; i++)
        {
            long long l=i-left[i];
            long long r=right[i]-i;

            long long totalWays=l*r;
            
           sum = (sum + (totalWays * arr[i]) % M) % M;
        }
        return sum;
    }
};