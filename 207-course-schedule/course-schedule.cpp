class Solution {

    void topo(vector<vector<int>>& adj,vector<bool>& visited, stack<int>& st,int node){

        visited[node] = true;
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                topo(adj,visited,st,neigh);
            }
        }
        st.push(node);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
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
        stack<int> st;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                st.push(i);
            }
        }
       int cnt = 0;
      while(!st.empty()){
        int top = st.top(); st.pop();
          cnt++;

        for(auto neigh : adj[top]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){
                st.push(neigh);
            }
        }
      }
      return (n == cnt);
    }
};