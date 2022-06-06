class Solution {
public:
    bool visited[251][251];
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        visited[i][j]=true;
        int ans=1;
        for(int k=0;k<m;k++){
            if(!visited[i][k]&&grid[i][k]==1) ans+=dfs(grid,i,k,n,m);
        }
        for(int k=0;k<n;k++){
            if(!visited[k][j]&&grid[k][j]==1) ans+=dfs(grid,k,j,n,m);
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int curr,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    curr=dfs(grid,i,j,n,m);
                    if(curr>1) ans+=curr;
                }
            }
        }
        return ans;
    }
};