class Solution {
public:
    void f(int i,int target,vector<int>& arr,vector<vector<int>>&ans, vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(i==arr.size()) return;

        //checking before picking it
        if(arr[i] <= target){
            ds.push_back(arr[i]); //pick it
            f(i,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
        // not pick it
        f(i+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,arr,ans,ds);
        return ans;
    }
};