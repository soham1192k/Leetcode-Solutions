class Solution {
public:
    bool visited[51][51];
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool ok(int i,int j,int n,int m){
        return i<n&&i>=0&&j>=0&&j<m;
    }
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        visited[i][j]=true;
        int ans=1;
        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]==1) ans+=dfs(grid,nr,nc,n,m);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    maxx=max(maxx,dfs(grid,i,j,n,m));
                }
            }
        }
        return maxx;
    }
};