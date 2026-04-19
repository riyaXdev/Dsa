class Solution {
    void dfss(int node,int parent,vector<vector<int>>& adj, vector<bool>& visited,vector<int>&  disc ,vector<int>& low, vector<vector<int>>& ans,int&count){
     disc[node] = low[node] = count;
     visited[node] = true;
     for(auto neigh : adj[node]){
        if(neigh == parent) continue;
        else if( visited[neigh]){
            low[node] = min(disc[neigh],low[node]);
        }
        else{
            count++;
            dfss(neigh,node,adj,visited,disc,low,ans,count);
            low[node] = min(low[neigh], low[node]);
            if(disc[node] < low[neigh]){
                //bridge present
                ans.push_back({node,neigh});
            }
        }
     }

       
   }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,0);
        vector<int>low(n); //low value
        vector<int>disc(n); //discovery time
        int count = 0;
        vector<vector<int>> ans;
        dfss(0,-1,adj,visited,disc,low,ans,count);
        return ans;
    }
};