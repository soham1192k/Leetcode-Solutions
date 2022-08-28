class Solution {
public:
    vector<int>adj[401];
    int indegree[401];
    void kahn(int n,vector<int>&order){
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            order.push_back(curr);
            for(auto edge:adj[curr]){
                indegree[edge]--;
                if(indegree[edge]==0) q.push(edge);
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<r.size();i++) {adj[r[i][0]].push_back(r[i][1]);indegree[r[i][1]]++;}
        vector<int>row_order,col_order;
        kahn(k,row_order);
        for(int i=1;i<=k;i++) {adj[i].clear();indegree[i]=0;}
        for(int i=0;i<c.size();i++) {adj[c[i][0]].push_back(c[i][1]);indegree[c[i][1]]++;}
        kahn(k,col_order);
        if(col_order.size()!=k||row_order.size()!=k) return {};
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++) mp[col_order[i]]=i;
        for(int i=0;i<k;i++) ans[i][mp[row_order[i]]]=row_order[i];
        return ans;
    }
};