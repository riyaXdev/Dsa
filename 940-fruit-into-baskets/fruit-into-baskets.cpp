class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int l=0,maxlen=0;
        unordered_map<int,int>mpp;
        for(int r=0; r<arr.size() ;r++){
             mpp[arr[r]]++;
             while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
             }
             maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};