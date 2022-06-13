class Solution {
public:
    int dp[35][35];
    vector<int> getRow(int rowIndex) {
        dp[0][0]=1;
        for(int i=1;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j==0) dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<=rowIndex;i++) ans.push_back(dp[rowIndex][i]);
        return ans;
    }
};