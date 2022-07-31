class Solution {
public:
    vector<int>adj[100005];
    bool visited[100005];
    int longest=-1;
    void dfs(int src,vector<int>&path){
        visited[src]=true;
        path.push_back(src);
        for(auto edge:adj[src]){
            if(!visited[edge]) dfs(edge,path);
            else{
                for(int i=path.size()-1;i>=0;i--){
                    if(path[i]==edge) {longest=max(longest,(int)path.size()-i);return;}
                }
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }
        vector<int>path;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                path.clear();
                dfs(i,path);
            }
        }
        return longest;
    }
};