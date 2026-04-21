class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node){
        for(auto neigh: graph[node]){
            if(color[neigh] == -1){
                color[neigh] = (color[node] + 1) % 2;
                if(!(dfs(graph,color,neigh))){
                    return false;                    
                }
                
            }
            else{
                if(color[neigh] == color[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //using dfs
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
              if(color[i]== -1){
                color[i] = 0;
                if(!dfs(graph,color,i)) return false;
              }
        }
        return true;
    }
};