class Solution {
public:
    int dp[35][35];
    vector<vector<int>> generate(int numRows) {
        dp[0][0]=1;
        for(int i=1;i<=numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0) dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>tmp;
            for(int j=0;j<=i;j++){
                tmp.push_back(dp[i][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};