class Solution {
public:
    void merge(vector<int>&nums,int si,int ei,int mid)
    {
        vector<int>temp;
        int i=si;
        int j=mid+1;

        while(i<=mid && j<=ei)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else
            {
                temp.push_back(nums[j++]);
            }
        }

        while(i<=mid)
        {
           temp.push_back(nums[i++]); 
        }

        while(j<=ei)
        {
           temp.push_back(nums[j++]); 
        }

        int k=0;
        for(int idx=si; idx<=ei; idx++)
        {
            nums[idx]=temp[k++];
        }
    }

    int currPairs(vector<int>&nums,int si,int ei,int mid)
    {
        int j=mid+1;
        int count=0;

        for(int i=si; i<=mid; i++)
        {
            while(j<=ei && (long long)nums[i]>2*(long long)nums[j])
            {
                j++;
            }
            count+=(j-(mid+1));
        }
        return count;
    }
    int mergeSort(vector<int>&nums,int si,int ei)
    {
        int count=0;
        if(si>=ei) return count;
        int mid=si+(ei-si)/2;
        count+=mergeSort(nums,si,mid);
        count+=mergeSort(nums,mid+1,ei);
        count+=currPairs(nums,si,ei,mid);
        merge(nums,si,ei,mid);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};