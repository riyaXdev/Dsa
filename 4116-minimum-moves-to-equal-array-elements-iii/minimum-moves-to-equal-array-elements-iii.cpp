class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > maxi) maxi = nums[i];
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt += abs(maxi-nums[i]);
        }
        return cnt;
    }
};