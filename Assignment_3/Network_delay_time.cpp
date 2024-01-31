class Solution {
public:
    #define pii pair<int,int>
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto i:t){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pii,vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1,1e9);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto i=pq.top();
            int dis=i.first;
            int prev=i.second;
            pq.pop();
            for(auto j:adj[prev]){
                int wt=j.second;
                int curr=j.first;
                if(dist[curr]>dis+wt){
                    dist[curr]=dis+wt;
                    pq.push({dist[curr],curr});
                }
            }
        }
        int mx=*max_element(dist.begin()+1,dist.end());
        return mx==1e9?-1:mx;
    }
};