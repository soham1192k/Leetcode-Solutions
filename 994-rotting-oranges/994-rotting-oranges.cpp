class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool ok(int nr,int nc,int n,int m){
        return nr>=0&&nr<n&&nc>=0&&nc<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        bool visited[11][11];
        memset(visited,false,sizeof(visited));
        int dist[11][11];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dist[i][j]=1e9;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {q.push({i,j});visited[i][j]=true;dist[i][j]=0;}
            }
        }
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=curr.first+row[i];
                int nc=curr.second+col[i];
                if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]==1){
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                    dist[nr][nc]=1+dist[curr.first][curr.second];
                }
            }
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) maxx=max(maxx,dist[i][j]); 
            }
        }
        if(maxx==1e9) return -1;
        return maxx;
    }
};