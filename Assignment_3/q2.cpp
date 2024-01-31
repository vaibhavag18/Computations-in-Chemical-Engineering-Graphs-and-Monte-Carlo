class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        if(old==color) return image;
        dfs(image, sr, sc, old, color);
        return image;
        
    }

    void dfs(vector<vector<int>>& image, int i, int j,int old,int color){
        int row = image.size();
        int coloumn = image[0].size();
        if(i<0||i>=row||j<0||j>=coloumn||image[i][j]!=old) return;
        image[i][j]=color;
        dfs(image,i+1,j,old,color);
        dfs(image,i,j+1,old,color);
        dfs(image,i,j-1,old,color);
        dfs(image,i-1,j,old,color);
    
    }

};