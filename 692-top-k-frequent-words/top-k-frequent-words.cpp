class Solution {
    struct mycom{
        bool operator()(pair<int,string>& a, pair<int,string>& b){
            if(a.first == b.first){
                return a.second < b.second; //lexicographical 
            }
            return a.first > b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string , int> freq;
        for(auto &i:words){
            freq[i]++;
        }

        priority_queue<pair<int,string> ,vector<pair<int,string>>, mycom> pq;  
        for(auto &t : freq){
            pq.push({t.second,t.first});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){            
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};