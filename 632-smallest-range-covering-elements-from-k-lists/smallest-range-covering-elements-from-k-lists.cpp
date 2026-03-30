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
            int val = p.val;
            int es = p.epos;
            int as = p.apos;
            if(es+1 < nums[as].size()){
                dataa d1(nums[as][es+1], es+1, as);
                pq.push(d1);
                mini = pq.top().val;
                maxi = max(maxi,nums[as][es+1]);

                //now  check if i have got lesser range than earlier
                //update the range before inserting next element
                 if(maxi - mini < ans[1] - ans[0]){
                    ans[0] = mini;
                    ans[1] = maxi;
                }
            }
        } 
        return ans;
    }
};