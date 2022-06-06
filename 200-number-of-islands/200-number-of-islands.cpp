class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool visited[301][301];
    int cnt;
    bool ok(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]=='1') dfs(grid,nr,nc,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1') {cnt++;dfs(grid,i,j,n,m);}
            }
        }
        return cnt;
    }
};