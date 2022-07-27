class Solution {
public:
    bool visited[51][51];
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool inside(int nr,int nc,int n){
        return nr>=0&&nr<n&&nc>=0&&nc<n;
    }
    void dfs(vector<vector<int>>&grid,int r,int c,int n,int mid){
        if(grid[r][c]>mid) return;
        visited[r][c]=true;
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(inside(nr,nc,n)&&!visited[nr][nc]&&grid[nr][nc]<=mid) dfs(grid,nr,nc,n,mid);
        }
    }
    bool ok(vector<vector<int>>&grid,int n,int mid){
        memset(visited,false,sizeof(visited));
        dfs(grid,0,0,n,mid);
        if(visited[n-1][n-1]) return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int minn=2501,maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxx=max(maxx,grid[i][j]);
                minn=min(minn,grid[i][j]);
            }
        }
        int low=minn;
        int high=maxx;
        int mid,ans;
        while(low<=high){
            mid=low+(high-low)/2;
            if(ok(grid,n,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};