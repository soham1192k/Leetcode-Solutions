class Solution {
    const int INF = 1e9;
    const int G = 0, F = 1, W = 2;
    const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(!canReach(grid)) return -1; 
        auto newGrid = spreadFire(grid, INF);
        if(canReach(newGrid)) return INF;
        int lt = -1, rt = n*m+1, ans = rt;
        while(1+lt<rt){
            int mid = (lt+rt)/2;
            newGrid = spreadFire(grid, mid);
            if(canReach(newGrid)){
                ans = mid, lt = mid;
            }else{
                rt = mid;
            }
        }
        return ans;
    }
private:
    vector<vector<int>> spreadFire(const vector<vector<int>> &prevGrid, int time){
        vector<vector<int>> grid(prevGrid);
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==F){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty() && time--){
            int curLen = q.size();
            while(curLen--){
                auto [x,y] = q.front(); q.pop();
                for(const auto &dir: dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]==G){
                        grid[nx][ny] = F;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return grid;
    }
    bool canReach(vector<vector<int>> &grid){
        int n = grid.size(), m = grid[1].size();
        if(grid[0][0]==F || grid[n-1][m-1]==F) return 0;
        vector<vector<int>> myTime(n, vector<int>(m, INF)), fireTime(myTime);
        queue<pair<int,int>> myQueue, fireQueue;
        myQueue.push({0,0}); myTime[0][0] = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==F){
                    fireQueue.push({i,j});
                    fireTime[i][j] = 0;
                }
            }
        }
        while(!myQueue.empty()){
            auto [x, y] = myQueue.front(); myQueue.pop();
            for(const auto &dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                int nTime = myTime[x][y] + 1;
                if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]!=W && myTime[nx][ny]==INF){
                    myTime[nx][ny] = nTime;
                    myQueue.push({nx,ny});
                }
            }
        }
        while(!fireQueue.empty()){
            auto [x, y] = fireQueue.front(); fireQueue.pop();
            for(const auto &dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                int nTime = fireTime[x][y] + 1;
                if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]!=W && fireTime[nx][ny]==INF){
                    fireTime[nx][ny] = nTime;
                    fireQueue.push({nx,ny});
                }
            }
        }
        vector<vector<bool>> vis(n, vector<bool>(m)); 
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(const auto &dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]!=W && !vis[nx][ny] 
                && ( (myTime[nx][ny] < fireTime[nx][ny]) || 
                     (nx==n-1 && ny==m-1 && myTime[nx][ny] <= fireTime[nx][ny])
                   ) 
                ){
                    vis[nx][ny] = 1;
                    if(nx==n-1 && ny==m-1)
                        return true;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
};