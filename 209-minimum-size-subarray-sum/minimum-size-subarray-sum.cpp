class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l=0,r=0,sum=0,minlen=1e9;
        while(r<nums.size()){
            sum += nums[r];
            while(sum >= target){
                minlen = min(minlen,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(minlen==1e9) return 0;
        return minlen;
        
    }
};