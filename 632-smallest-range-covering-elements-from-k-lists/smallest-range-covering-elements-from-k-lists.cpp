class dataa{
   public: int val,epos,apos;
    dataa(int value,int es,int as){
        val = value;
        epos = es;
        apos = as;
    }
};
struct mycomp{
    bool operator()(dataa &d1, dataa &d2){
        return d1.val > d2.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=0,range ,maxi = INT_MIN;
        vector<int> ans(2);
        priority_queue<dataa, vector<dataa>, mycomp> pq;
        //inserting first elem of every array
        for(int i=0; i<nums.size(); i++){
            dataa d(nums[i][0], 0, i);
            maxi = max(maxi,nums[i][0]); //keep updating maximum element
            pq.push(d);
        }
        mini = pq.top().val;
        ans[0] = mini;
        ans[1] = maxi;
        while(pq.size() == nums.size()){  //jabtak no of rows ke barabar elements ho heap mei
           auto p = pq.top();
            pq.pop();

            int mini = p.val;

            // ✅ update answer FIRST
            if(ans.empty() || maxi - mini < ans[1] - ans[0]){
                ans = {mini, maxi};
            }

            int es = p.epos;
            int as = p.apos;

            // Step 3: move forward in same list
            if(es + 1 < nums[as].size()){
                int nextVal = nums[as][es + 1];
                pq.push(dataa(nextVal, es + 1, as));

                // ✅ correct indexing
                maxi = max(maxi, nextVal);
            }
        } 
        return ans;
    }
};