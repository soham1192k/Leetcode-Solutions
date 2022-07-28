class Solution {
public:
    bool visited[201][201];
    int cnt=0;
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    bool ok(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(vector<vector<char>>&board,int i,int j,int n,int m){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int nr=i+row[k];
            int nc=j+col[k];
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&board[nr][nc]=='X') dfs(board,nr,nc,n,m);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'&&!visited[i][j]) {dfs(board,i,j,n,m);cnt++;}
            }
        }
        return cnt;
    }
};