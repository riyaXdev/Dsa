class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int> ans;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto temp : adj[i]){
                 indegree[temp]++;
            }
        }
        queue<int> st;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                st.push(i);
            }
        }
    
      while(!st.empty()){
        int top = st.front(); st.pop();
          ans.push_back(top);

        for(auto neigh : adj[top]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){
                st.push(neigh);
            }
        }
      }
      if(ans.size() != n) return {};// always check for cycle
      return ans;
    }
};
