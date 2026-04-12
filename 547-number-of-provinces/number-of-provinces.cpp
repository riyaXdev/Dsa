class Solution {
    int findUlt(int u, vector<int>& parent){
        if(u == parent[u]) return u;
        return parent[u] = findUlt(parent[u], parent);
    }

    void UnionBy(int u, int v, vector<int>& parent,vector<int>& rank){
        int pu = findUlt(u,parent);
        int pv = findUlt(v,parent);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu]= pv; 
        }
        else if(rank[pu] == rank[pv]){
           parent[pu] = pv;
           rank[pv]++;
        }
        else{ //rank[pv] < rank[pu]
            parent[pv] = pu;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=1+i;j<n;j++){
                if(isConnected[i][j] == 1){
                    UnionBy(i,j,parent,rank);
                }
            }
        }
      for(int i=0;i<n;i++){
        if(parent[i] == i) cnt++;
      }
      return cnt;
    }
};