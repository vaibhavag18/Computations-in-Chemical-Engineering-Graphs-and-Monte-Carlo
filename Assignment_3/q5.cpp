class Solution {
public:
    set<int> g1,g2;
    const static int N = 2001;
    vector<int> adj[N];
    bool vis[N];

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
        return g1.size()+g2.size()==n;
    }

    void dfs(int u, bool g){
        (g)? g1.insert(u):g2.insert(u);
        if(vis[u]) return;
        vis[u]=1;
        for(auto v:adj[u]) {
            bool check= !g;
            dfs(v,check);
        }
    }
};