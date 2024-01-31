class Solution {
public:
    // void dfs(int row,int col,int delrow[], int delcol[],vector<vector<int>> &image,int icolor,int newcolor){
    //     int m=image.size();
    //     int n=image[0].size();
    //     image[row][col]=newcolor;
    //     for(int i=0; i<4; i++){
    //       int nrow=row+delrow[i];
    //       int ncol=col+delcol[i];
    //       if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==icolor){
    //            dfs(nrow,ncol,delrow,delcol,image,icolor,newcolor);
    //       }
    //     } 
    // }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int
     newcolor) {
        //by bfs
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int icolor= image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=newcolor;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow= node.first+dx[i];
                int ncol= node.second+dy[i];
                if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && 
                image[nrow][ncol]==icolor && image[nrow][ncol]!=newcolor){
                    image[nrow][ncol]=newcolor;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
        //by dfs
        // int icolor= image[sr][sc];
        // int delrow[]={-1,0,1,0};
        // int delcol[]={0,1,0,-1};
        // if(icolor!=newcolor) dfs(sr,sc,delrow,delcol,image,icolor,newcolor);
        // return image;
    }
};