class Solution {
    void solve(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& temp,
                          int src, int dest){
                
               temp.push_back(src);
               if(src == dest){
                  ans.push_back(temp);
               }
               else {
                for(auto i:graph[src]){
                    solve(graph,ans,temp,i,dest);
                }
               }
 
     temp.pop_back(); }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp; //temporary vector to store paths
        int n = graph.size();
        solve(graph,ans,temp,0,n-1);

        return ans;
    }
};