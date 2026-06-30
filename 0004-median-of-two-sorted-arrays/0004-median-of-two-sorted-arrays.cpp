class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int i=0;
        int j=0;
        int k=0;

        vector<int>temp(n+m);

        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
               temp[k++]=nums1[i++];
            }
            else
            {
                temp[k++]=nums2[j++];
            }
        }

        while(i<nums1.size())
        {
            temp[k++]=nums1[i++];
        }

        while(j<nums2.size())
        {
            temp[k++]=nums2[j++];
        }

        if((n+m) % 2 == 1)
        {
            return temp[(n+m)/2];
        }
        return (temp[(n+m)/2]+temp[(n+m)/2-1])/2.0;
    }
};