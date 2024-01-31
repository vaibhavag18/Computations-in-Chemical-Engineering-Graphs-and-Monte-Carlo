class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool> &vis,vector<bool> &dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto &i:adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsvis))return 1;
            }
            else if(dfsvis[i])return 1;
        }
        dfsvis[node]=0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(auto &i:p){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(n,0),dfsvis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsvis))return 0;
            }
        }
        return 1;
    }
};