class Solution {
public:
    vector<int>adj[100005];
    bool visited[100005];
    void dfs(int src){
        visited[src]=true;
        for(auto edge:adj[src]){
            if(!visited[edge]) dfs(edge);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        map<int,bool>mp;
        for(auto x:restricted) mp[x]=true;
        for(auto x:edges){
            if(mp[x[0]]||mp[x[1]]) continue;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visited[i]) cnt++;
        }
        return cnt;
    }
};