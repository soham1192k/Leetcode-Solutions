class Solution {
public:
    vector<pair<int,int>>adj[1001];
    int visited[1001];
    int maxx;
    void dfs(vector<int>&val,int src,int time,int curr){
        if(!visited[src]) curr+=val[src]; 
        visited[src]++;
        if(src==0) maxx=max(maxx,curr);
        for(auto edge:adj[src]){
            if(time-edge.second>=0) dfs(val,edge.first,time-edge.second,curr);
        }
        visited[src]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        dfs(values,0,maxTime,0);
        return maxx;
    }
};