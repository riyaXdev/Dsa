class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int pos = -1;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] > max1){
                max1 = nums[i];
                pos = i;
            }
        }
        for(int j =0; j<nums.size(); j++){
            if(j == pos) continue;
            if(nums[j] > max2){
                max2 = nums[j];
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};