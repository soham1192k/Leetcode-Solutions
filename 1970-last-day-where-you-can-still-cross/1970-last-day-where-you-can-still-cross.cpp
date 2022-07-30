class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool ok(int nr,int nc,int n,int m){
        return nr>=0&&nr<n&&nc>=0&&nc<m;
    }
    void bfs(vector<vector<int>>&grid,int n,int m,vector<vector<bool>>&visited){
        queue<pair<int,int>>q;
        for(int j=0;j<m;j++){
            if(grid[0][j]==0) {q.push({0,j});visited[0][j]=true;}
        }
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=curr.first+row[i];
                int nc=curr.second+col[i];
                if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]==0){
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                }
            }
        }
    }
    bool ok(int n,int m,int mid,vector<vector<int>>&cells){
        vector<vector<int>>grid(n,vector<int>(m));
        for(int i=0;i<mid;i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        bfs(grid,n,m,visited);
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==0&&visited[n-1][j]) return true;
        }
        return false;
    }
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int low=1,high=cells.size();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ok(n,m,mid,cells)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};