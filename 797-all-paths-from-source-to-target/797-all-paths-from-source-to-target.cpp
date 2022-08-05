class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int src,vector<vector<int>>&graph,int n,vector<int>&path){
        path.push_back(src);
        if(src==n-1) {ans.push_back(path);path.pop_back();return;}
        for(auto edge:graph[src]) dfs(edge,graph,n,path);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        dfs(0,graph,graph.size(),path);
        return ans;
    }
};