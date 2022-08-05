class Solution {
public:
    int dp[1001];
    int func(vector<int>&nums,int target){
        if(target<0) return 0;
        else if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(auto x:nums) ans+=func(nums,target-x);
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return func(nums,target);
    }
};