class Solution {
public:
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size=isConnected.size();
        vector<vector<int>> v(size, vector<int> ());
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(i!=j && isConnected[i][j]==1){
                    v[i].emplace_back(j);
                }
            }
        }
        vector<int> vis(size,0);
        int ans=0;
        for(int i=0; i<size; i++){
            if(vis[i]!=1){
                ans++;
                dfs(i, vis, v);
            }
        }
        return ans;
    }

    void dfs(int node, vector<int> &vis, vector<vector<int>> &v){
        vis[node]=1;
        for(auto &child: v[node]){
            if(vis[child]!=1) dfs(child, vis, v );
        }
    }
};