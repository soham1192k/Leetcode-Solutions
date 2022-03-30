class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n][2];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) {dp[i][i][0]=nums[i];dp[i][i][1]=-nums[i];}
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j][0]=max(dp[i][j-1][1]+nums[j],dp[i+1][j][1]+nums[i]);
                dp[i][j][1]=min(dp[i][j-1][0]-nums[j],dp[i+1][j][0]-nums[i]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        int twoplayer=sum+dp[0][n-1][0];
        if(twoplayer>=sum) return true;
        return false;
    }
};