class Solution {
    private:
    void dfs(unordered_map<int,bool>& visited,int src,vector<vector<int>>& isConnected){
        visited[src]=true;
        int size=isConnected.size();
        for(int col=0;col<isConnected[src].size();col++){
            if(src!=col&& isConnected[src][col]==1){
                if(!visited[col])
                    dfs(visited,col,isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_map<int,bool> visited;
    int count=0;
    int n=isConnected.size();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(visited,i,isConnected);
            count++;
        }
    }
    return count;
    }
};