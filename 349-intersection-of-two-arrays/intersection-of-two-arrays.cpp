class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>st;
        for(int i:nums1){
            st.insert(i);
        }
        for(int j:nums2){
            if(st.contains(j)){
                ans.push_back(j);
                st.erase(j);
            }
        }
        return ans;
    }
};