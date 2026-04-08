class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        if(s.length() <= 1) return ans;
        unordered_map<char,int> freq;
        for(auto i: s){
            freq[i]++;
        }
       priority_queue<pair<int,char>> pq;
        for(auto t: freq){
            pq.push({t.second,t.first});
        }

        while(!pq.empty()){
             auto xyz = pq.top();
             pq.pop();
             while(xyz.first){
                ans+= xyz.second;
                xyz.first--;
             }
        }
        return ans;
    }
};