class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 && i<n-1 && j>0 && j<m-1) continue;
                if(board[i][j]=='O'){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto d:dir){
                int row=x+d[0];
                int col=y+d[1];
                if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='O' && visited[row][col]==0){
                    visited[row][col]=1;
                    q.push({row,col});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};