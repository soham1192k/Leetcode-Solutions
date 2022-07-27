class Solution {
public:
    bool visited[101][101];
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool inside(int nr,int nc,int r,int c){
        return nr>=0&&nr<r&&nc>=0&&nc<c;
    }
    void dfs(vector<vector<int>>&heights,int r,int c,int n,int m,int mid){
        visited[r][c]=true;
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(inside(nr,nc,n,m)&&!visited[nr][nc]&&abs(heights[nr][nc]-heights[r][c])<=mid) dfs(heights,nr,nc,n,m,mid);
        }
    }
    bool ok(vector<vector<int>>&heights,int n,int m,int mid){
        memset(visited,false,sizeof(visited));
        dfs(heights,0,0,n,m,mid);
        if(visited[n-1][m-1]) return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int low=0;
        int high=1e6,ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ok(heights,n,m,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};