class Solution {
public:
    vector<int>adj[201];
    bool visited[201];
    void dfs(int src){
        visited[src]=true;
        for(auto edge:adj[src]){
            if(!visited[edge]) dfs(edge);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j) {adj[i+1].push_back(j+1);adj[j+1].push_back(i+1);}
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!visited[i]) {dfs(i);cnt+=1;}
        }
        return cnt;
    }
};