class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (auto& adjNode : adj[node]) {
            if (!visited[adjNode]) dfs(adjNode, adj, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) adj[i].emplace_back(j);
            }
        }
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                provinces++;
                dfs(node, adj, visited);
            }
        }

        return provinces;
    }
    
};