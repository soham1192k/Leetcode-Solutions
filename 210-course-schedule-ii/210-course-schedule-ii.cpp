class Solution {
public:
    vector<int>adj[2001];
    int indegree[2001];
    vector<int>order;
    vector<int> kahn(int n){
        int cnt=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            cnt++;
            order.push_back(v);
            for(auto edge:adj[v]){
                indegree[edge]--;
                if(indegree[edge]==0) q.push(edge);
            }
        }
        if(cnt!=n) return {};
        return order;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }
        vector<int>order = kahn(n);
        return order;
    }
};