class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minindex = 0,maxindex = 0;
        int mini = nums[0], maxi = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] < mini){
                mini = nums[i];
                minindex = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                maxindex = i;
            }
        }
        int left = min(minindex,maxindex);
        int right = max(minindex,maxindex);


        int front = right + 1; // agar aage se dono delete karenge
        int back = n - left; //agar peeche se dono delete kareneg 
        int both  = (left + 1) + (n-right); // agar dono end se ek ek delete karo
        
        return min({front,back,both});

    }
};