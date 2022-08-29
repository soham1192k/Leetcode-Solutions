class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') dp[i][j]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1') dp[i][j]=max(dp[i][j],1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}));
            }
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) maxx=max(maxx,dp[i][j]);
        }
        return maxx*maxx;
    }
};