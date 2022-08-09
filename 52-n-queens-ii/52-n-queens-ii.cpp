class Solution {
public:
    vector<vector<string>>ans;
    int cnt;
    bool ok(int i,int j,int n,vector<string>&hold){
        int k=0,l=0;
        for(k=0;k<n;k++){
            if(hold[k][j]=='Q') return false;
        }
        for(l=0;l<n;l++){
            if(hold[i][l]=='Q') return false;
        }
        for(k=i,l=j;k<n&&l>=0;k++,l--){
            if(hold[k][l]=='Q') return false;
        }
        for(k=i,l=j;k>=0&&l<n;k--,l++){
            if(hold[k][l]=='Q') return false;
        }
        for(k=i,l=j;k>=0&&l>=0;k--,l--){
            if(hold[k][l]=='Q') return false;
        }
        for(k=i,l=j;k<n&&l<n;k++,l++){
            if(hold[k][l]=='Q') return false;
        }
        return true;
    }
    void dfs(int row,int n,vector<string>&hold){
        if(row==n){
            ans.push_back(hold);
            return;
        }
        for(int col=0;col<n;col++){
            if(ok(row,col,n,hold)){
                hold[row][col]='Q';
                dfs(row+1,n,hold);
                hold[row][col]='.';
            }
        }   
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=1;i<=n;i++) s+='.';
        vector<string>hold;
        for(int i=0;i<n;i++) hold.push_back(s);
        dfs(0,n,hold);
        return ans;
    }
};