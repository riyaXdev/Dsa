class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;
        int mid = total / 2;
        int i=0,j=0,prev=0,curr=0;
        for(int k=0;k<=mid;k++){
            prev = curr;
            if(i<m && (j>=n || nums1[i] <= nums2[j])){
                curr = nums1[i];
                i++;
            }
            else{
                curr = nums2[j];
                j++;
            }
        }
        if(total % 2 == 1) return curr;
        return (prev + curr)/2.0;
    }
};