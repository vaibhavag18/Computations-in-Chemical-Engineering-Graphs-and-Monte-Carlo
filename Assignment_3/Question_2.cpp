class Solution {
public:

    int initialcol;
    int col;

    void helper(vector<vector<int>> &arr, int a, int b){
        int n = arr.size();
        int m = arr[0].size();

        if(a<0 || b<0 || a>=n || b>=m) return;

        if(arr[a][b]!=initialcol) return;

        arr[a][b] = col;

        helper(arr,a,b+1);
        helper(arr,a,b-1);
        helper(arr,a-1,b);
        helper(arr,a+1,b);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        initialcol = arr[sr][sc];
        col = color;
        if(initialcol==col) return arr;
        helper(arr,sr,sc);
        return arr;
    }
};