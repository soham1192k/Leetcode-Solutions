class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) dp[i][j]=1e9;
        }
        for(int j=0;j<n;j++) dp[n-1][j]=matrix[n-1][j];
        for(int i=n-2;i>=0;i--){
            dp[i][0]=min(dp[i+1][0],dp[i+1][1])+matrix[i][0];
            for(int j=1;j<=n-2;j++){
                dp[i][j]=min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]})+matrix[i][j];
            }
            dp[i][n-1]=min(dp[i+1][n-2],dp[i+1][n-1])+matrix[i][n-1];
        }
        int minn=1e9;
        for(int j=0;j<n;j++) minn=min(minn,dp[0][j]);
        return minn;
    }
};