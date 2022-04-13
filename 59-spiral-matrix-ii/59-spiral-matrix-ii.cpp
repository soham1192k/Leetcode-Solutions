class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int ptr=0;
        int row=0;
        int upto=n/2;
        if(n%2==0) upto--;
        while(row<=upto){
            for(int j=row;j<n-1-row;j++){
                if(ans[row][j]==0) ans[row][j]=++ptr;
            }
            for(int i=row;i<n-1-row;i++){
                if(ans[i][n-1-row]==0) ans[i][n-1-row]=++ptr;
            }
            for(int j=n-1-row;j>=row;j--){
                if(ans[n-1-row][j]==0) ans[n-1-row][j]=++ptr;
            }
            for(int i=n-1-row;i>=row;i--){
                if(ans[i][row]==0) ans[i][row]=++ptr;
            }
            row++;
        }
        return ans;
    }
};