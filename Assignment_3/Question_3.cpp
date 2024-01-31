class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visit, int x, int y, int h){
        if (x<0 || y<0 || x>=heights.size() || y>=heights[0].size() || visit[x][y] == true || heights[x][y]<h){
            return;
        }
        h=heights[x][y];
        visit[x][y] = true;
        dfs(heights,visit,x-1,y,h);
        dfs(heights,visit,x+1,y,h);
        dfs(heights,visit,x,y-1,h);
        dfs(heights,visit,x,y+1,h);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> mapP(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> mapA(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<int>> ans;
        for (int i=0;i<heights.size();i++){
            dfs(heights,mapP,i,0,-1);
            dfs(heights,mapA,i,heights[0].size()-1,-1);
        }
        
        for (int j=0;j<heights[0].size();j++){
            dfs(heights,mapP,0,j,-1);
            dfs(heights,mapA,heights.size()-1,j,-1);
        }
        
        for (int i=0;i<heights.size();i++){
            for (int j=0;j<heights[0].size();j++){
                if (mapP[i][j] && mapA[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};