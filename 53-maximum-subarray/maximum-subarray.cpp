class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maximum = INT_MIN;
        for(int x : nums){
            currsum += x;
            maximum = max(currsum,maximum);
            if(currsum<0){
                currsum = 0;
            }
        }
        return maximum;
    }
};