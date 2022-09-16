class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        int dp[m+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int op=m-1;op>=0;op--){
            for(int left=op;left>=0;left--){
                dp[op][left]=max(dp[op+1][left+1]+multipliers[op]*nums[left],dp[op+1][left]+multipliers[op]*nums[n-1-op+left]);
            }
        }
        return dp[0][0];
    }
};