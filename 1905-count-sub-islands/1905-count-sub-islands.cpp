class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    int cc;
    int cnt;
    map<pair<int,int>,int>mp;
    bool visited[501][501];
    bool ok(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        visited[i][j]=true;
        mp[{i,j}]=cc;
        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]==1) dfs(grid,nr,nc,n,m);
        }
    }
    void dfs1(vector<vector<int>>&grid,int i,int j,int n,int m,vector<pair<int,int>>&comp){
        visited[i][j]=true;
        comp.push_back({i,j});
        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&grid[nr][nc]==1) dfs1(grid,nr,nc,n,m,comp);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid1[i][j]==1) {cc++;dfs(grid1,i,j,n,m);}
            }
        }
        memset(visited,false,sizeof(visited));
        vector<pair<int,int>>comp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid2[i][j]==1){
                    comp.clear();
                    dfs1(grid2,i,j,n,m,comp);
                    int orig=mp[comp[0]];
                    bool flag=true;
                    if(orig==0) flag=false;
                    for(int i=1;i<(int)comp.size();i++){
                        if(mp[comp[i]]!=orig) {flag=false;break;}
                    }
                    if(flag) {cnt++;cout<<"YES\n";}
                }
            }
        }
        return cnt;
    }
};