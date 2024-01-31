class Solution {
public:
  void func(int s, int n, vector<vector<int>>& isConnected, vector<bool>&alvisit){
        alvisit[s] = true;
        // s = 1
        vector<int>adj;
        for(int i=0; i<n; i++ ){
            int x =  isConnected[s][i];
            if(x == 1)
                adj.push_back(i);
        }
        
        for(auto x: adj){
            if(!alvisit[x]){
                func(x, n, isConnected, alvisit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
           int n = isConnected.size();
        vector<bool>alvisit(n, false);
        int num = 0;
        
        for(int i=0; i<n; i++){
            if(!alvisit[i]){
                num++;
                func(i, n, isConnected, alvisit);
            }
        }
        
        return num;   
    }
};