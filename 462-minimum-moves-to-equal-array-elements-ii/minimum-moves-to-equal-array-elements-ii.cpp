class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int target = nums[n/2];
        long long count = 0;
        for(int it:nums){
            count+= abs(it-target);
        }
        return count;
    }
};