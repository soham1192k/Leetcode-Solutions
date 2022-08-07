class Solution {
public:
    int ans=0;
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool ok(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(int i,int j,int dest_x,int dest_y,int n,int m,vector<vector<int>>&grid,vector<vector<bool>>&visited){
        if(i==dest_x&&j==dest_y){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]!=-1&&!visited[i][j]) return;
                }
            }
            ans++;
            return;
        }
        for(int k=0;k<4;k++){
            int nr=i+row[k];
            int nc=j+col[k];
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]!=-1){
                visited[nr][nc]=true;
                dfs(nr,nc,dest_x,dest_y,n,m,grid,visited);
                visited[nr][nc]=false;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sx,sy,dx,dy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {sx=i;sy=j;}
                if(grid[i][j]==2) {dx=i;dy=j;}
            }
        }
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        visited[sx][sy]=true;
        dfs(sx,sy,dx,dy,n,m,grid,visited);
        return ans;
    }
};