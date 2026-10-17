class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int rsum=0,lsum=0;
        for(int i=0;i<k;i++) lsum += arr[i];
        int rindex =n-1;
        int sum = lsum + rsum;
        for(int i=k-1;i>=0;i--){
              lsum -= arr[i];
              rsum += arr[rindex];
              sum = max(sum, lsum + rsum);
              rindex--;
        }
        return sum;
    }
};