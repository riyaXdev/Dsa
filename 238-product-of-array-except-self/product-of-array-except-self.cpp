class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int left = 1,right = 1;
        for(int i=0;i<n;i++){
           ans[i] *= left;
            left *= nums[i];
            //ans[i] *= left;
        }
        for(int i=n-1;i>=0;i--){
           ans[i] *= right;
            right *= nums[i];
            //ans[i] *= right;
        }
        return ans;
    }
};