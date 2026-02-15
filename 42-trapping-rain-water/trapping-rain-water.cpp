class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        vector<int> leftt(n);
        vector<int> rightt(n);
        vector<int> ans(n);
        leftt[0] = height[0];
        for(int i=1 ;i<n; i++){
             leftt[i]= max(leftt[i-1],height[i]);
        }
        rightt[n-1] = height[n-1];
        for(int j=n-2; j>=0; j--){
            rightt[j] = max(rightt[j+1],height[j]);
        }
        for(int i=0; i<n; i++){
            ans[i] = min(leftt[i],rightt[i]) - height[i];
        }
        int sum = 0;
        for(int i=0; i<n;i++){
            sum += ans[i];
        }
        return sum;

    }
};