class Solution {

    void dfs(int node, vector<vector<int>>& adj, vector<bool>&restrict,vector<bool>&visited, int &count){
        visited[node] = true;
        for(auto neigh : adj[node]){
            if(!restrict[neigh] && !visited[neigh] ){
                count++;
                dfs(neigh,adj,restrict,visited,count);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,0);
        vector<bool>restrict(n,0);
        for(int i=0;i<restricted.size();i++){
            restrict[restricted[i]] = 1;
        }
        int count = 1;
        dfs(0,adj,restrict,visited,count);
        return count;


    }
};