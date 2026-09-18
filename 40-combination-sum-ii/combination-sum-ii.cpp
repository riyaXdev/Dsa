class Solution {
public:
    void f(int index,int target,vector<vector<int>>&ans,vector<int>&ds,vector<int>&arr){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<arr.size(); i++){
            //do not take duplicates at same level
            if(i>index && arr[i] == arr[i-1]){
                continue;
            }
            //pruning
            if(target < arr[i]) break;

            //choose element
            ds.push_back(arr[i]);
            //aage badho same element cannot be choosen again
            f(i+1,target-arr[i],ans,ds,arr);
            //pop back
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(arr.begin(),arr.end());
        f(0,target,ans,ds,arr);
        return ans;
    }
};