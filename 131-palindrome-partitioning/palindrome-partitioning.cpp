class Solution {
    bool ispalind(int start,int end,string s){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void f(int index,string s,vector<vector<string>>&ans,vector<string>&ds){
        if(index == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<s.size() ;i++){
            if(ispalind(index,i,s) == true){
                string st = s.substr(index,i-index+1);
                ds.push_back(st);
                 f(i+1,s,ans,ds);
                 ds.pop_back();
            }            
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        string st = "";
        f(0,s,ans,ds);
        return ans;
    }
};