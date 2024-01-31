class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &color,int node){
        if(color[node]==-1)color[node]=1;
        for(auto i:adj[node]){
            if(color[i]==-1){
                color[i]=1-color[node];
                if(dfs(adj,color,i))return true;
            }
            else if(color[i]==color[node])return true;
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> adj(n+1);
        for(auto i:d){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> color(n+1,-1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1)if(dfs(adj,color,i))return false;
        }
        return true;
    }
};