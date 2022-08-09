class Solution {
public:
    bool visited[10][10];
    int ans;
    bool ok(int i,int j,int n){
        int k=0,l=0;
        for(k=0;k<n;k++){
            if(visited[k][j]) return false;
        }
        for(l=0;l<n;l++){
            if(visited[i][l]) return false;
        }
        for(k=i,l=j;k<n&&l>=0;k++,l--){
            if(visited[k][l]) return false;
        }
        for(k=i,l=j;k>=0&&l<n;k--,l++){
            if(visited[k][l]) return false;
        }
        for(k=i,l=j;k>=0&&l>=0;k--,l--){
            if(visited[k][l]) return false;
        }
        for(k=i,l=j;k<n&&l<n;k++,l++){
            if(visited[k][l]) return false;
        }
        return true;
    }
    void dfs(int row,int n){
        if(row==n) {ans++;return;}
        for(int col=0;col<n;col++){
            if(ok(row,col,n)){
                visited[row][col]=true;
                dfs(row+1,n);
                visited[row][col]=false;
            }
        }
    }
    int totalNQueens(int n) {
        dfs(0,n);
        return ans;
    }
};