    class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>st(nums1.begin(),nums1.end());
        for(int i:nums1){
            st.insert(i);
        }
        for(int j:nums2){
            if(st.find(j) != st.end()){
                ans.push_back(j);
                st.erase(j);
            }
        }
        return ans;
    }
};
