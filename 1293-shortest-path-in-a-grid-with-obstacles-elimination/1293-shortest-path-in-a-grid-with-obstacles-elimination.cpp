class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        queue<vector<int>>q;
        bool visited[m][n][k+1];
        memset(visited,false,sizeof(visited));
        q.push({0,0,k});
        visited[0][0][k]=true;
        while(!q.empty()) {
            int size=q.size();
            for(int z=0;z<size;z++) {
                auto p = q.front();
                q.pop();
                if(p[0]==m-1&&p[1]==n-1) return ans;
                for(int x=0;x<4;x++) {
                    int i= p[0]+row[x];
                    int j= p[1]+col[x];
                    int obstacle = p[2];
                    if(i>=0 && i<m && j>=0 && j<n) {
                      if(grid[i][j]==0 && !visited[i][j][obstacle])  {
                          q.push({i,j,obstacle});
                          visited[i][j][obstacle] =true;
                      } else if(grid[i][j]==1 && obstacle>0 && !visited[i][j][obstacle-1]) {
                          q.push({i,j,obstacle-1});
                          visited[i][j][obstacle-1]=true;
                      }
                    } 
                }
            }
            ans++;
        }
        return -1;
    }
};