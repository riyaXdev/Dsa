class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans(arr.size());
        int n = arr.size();
        ans[n-1] = -1;
        int largest = arr[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] = largest;
            if(arr[i] > largest){
                largest = arr[i];
            }
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};