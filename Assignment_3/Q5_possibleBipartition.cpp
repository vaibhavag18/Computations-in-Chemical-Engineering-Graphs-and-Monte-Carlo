class Solution {
void make(int n,int size[],int par[]){
    for(int i=0;i<n;i++){
        size[i] = 1;
        par[i] = i;
    }
}
int find(int a,int par[]){
    if(par[a]==a){
        return a;
    }
    par[a] = find(par[a],par);
    return par[a];
}
void Union(int a,int b,int size[],int par[]){
    a = find(a,par);
    b = find(b,par);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        size[a]+=size[b];
        par[b] = a;
    }
}
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       int size[n+2];
       int par[n+2];
       make(n+2,size,par);
       int exchange[n];
       for(int i=0;i<n;i++){
           exchange[i] = -1;
       }
       for(int i=0;i<dislikes.size();i++){
               int aa = dislikes[i][0];
               int bb = dislikes[i][1];
               aa--;
               bb--;
               if(exchange[aa]==-1 and exchange[bb]==-1){
                   exchange[aa] = bb;
                   exchange[bb] = aa;
               }
               else if(exchange[aa]==-1){
                   exchange[aa] = bb;
                   Union(exchange[bb],aa,size,par);
               }
               else if(exchange[bb]==-1){
                   exchange[bb] = aa;
                   Union(exchange[aa],bb,size,par);
               }
               else{
                   if(find(aa,par)==find(bb,par)){
                       return 0;
                   }
                   Union(exchange[aa],bb,size,par);
                   Union(exchange[bb],aa,size,par);
               }
       }
       return true;
    }
};