class Solution {
public:
    int indegree[2001];
    vector<int>adj[2001];
    bool kahn(int n){
        queue<int>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            cnt++;
            for(auto edge:adj[v]){
                indegree[edge]--;
                if(indegree[edge]==0) q.push(edge);
            }
        }
        if(cnt!=n) return false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }
        return kahn(n);
    }
};