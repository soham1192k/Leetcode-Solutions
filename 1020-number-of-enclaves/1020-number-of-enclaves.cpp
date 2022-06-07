class Solution {
public:
    bool visited[501][501];
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool ok(int i,int j,int n,int m){
        return i>=0&&j>=0&&j<m&&i<n;
    }
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]==1) dfs(grid,nr,nc,n,m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int j=0;j<m;j++){
            if(!visited[0][j]&&grid[0][j]==1) dfs(grid,0,j,n,m);
            if(!visited[n-1][j]&&grid[n-1][j]==1) dfs(grid,n-1,j,n,m);
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0]&&grid[i][0]==1) dfs(grid,i,0,n,m);
            if(!visited[i][m-1]&&grid[i][m-1]==1) dfs(grid,i,m-1,n,m); 
        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1&&!visited[i][j]) cnt++;
            }
        }
        return cnt;
    }
};