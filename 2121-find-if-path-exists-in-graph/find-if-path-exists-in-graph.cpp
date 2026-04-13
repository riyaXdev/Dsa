class Solution {

    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int src, int dest){
        visited[src] = true;
        if(src == dest){
            return true;
        }
        else{
            for(auto i:adj[src]){
                if(!visited[i]){
                   if(dfs(adj,visited,i,dest)) return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,0);
         return dfs(adj,visited,source,destination);
    }
};