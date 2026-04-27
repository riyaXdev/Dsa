class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Store ancestors
        vector<set<int>> ancestors(n);

        // Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : adj[u]) {
                // Add u as ancestor
                ancestors[v].insert(u);

                // Add all ancestors of u
                for (auto x : ancestors[u]) {
                    ancestors[v].insert(x);
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Convert set to vector
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return ans;
    }
};