class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = -1e9;
        double sum = 0;
        int l=0,r=0;
        while(r<nums.size()){
               sum+=nums[r];
               if(r-l+1==k){
               // double ans = sum/k;
                avg = max(avg,sum/k);
                sum-=nums[l];
                l++;
               }
               r++;
        }
        return avg;
    }
};