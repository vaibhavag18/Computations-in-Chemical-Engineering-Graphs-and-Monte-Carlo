class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    void dfs(int i,int j,vector<vector<char>>& a){
        a[i][j]='R';
        for(int k=0; k<4; k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<a.size() && y>=0 && y<a[0].size() && a[x][y]=='O')dfs(x,y,a);
        }
    }

    void solve(vector<vector<char>>& a) {
        int m=a.size(),n=a[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && a[i][j]=='O')dfs(i,j,a);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]=='O')a[i][j]='X';
                else if(a[i][j]=='R')a[i][j]='O';
            }
        }
    }
};