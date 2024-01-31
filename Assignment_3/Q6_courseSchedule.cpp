class Solution {
    bool topoSortBFS(int n,unordered_map<int,list<int>>& adj){
        vector<int> ans;
        unordered_map<int,int> indegree;
        queue<int> q;
        for(auto i:adj){
            for(auto nbr:i.second)
                indegree[nbr]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int fnode=q.front();
            q.pop();
            ans.push_back(fnode);
            for(auto nbr : adj[fnode]){
                indegree[nbr]--;
                    if(indegree[nbr] == 0) {
                        q.push(nbr);
                    }
            }
        }
        if(ans.size()==n)
            return true;
            return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(auto task:prerequisites){
            int u=task[0];
            int v=task[1];
            adj[u].push_back(v);
        }
        return topoSortBFS(numCourses,adj);
    }
};