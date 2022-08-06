class Solution {
public:
    int dp[19][1<<9][1<<9];
    int func(vector<int>&nums,int n,int idx,int mask1,int mask2,int slots){
        if(idx==n) return 0;
        if(dp[idx][mask1][mask2]!=-1) return dp[idx][mask1][mask2];
        int ans=0;
        for(int i=0;i<slots;i++){
            int b1=(mask1&(1<<i));
            int b2=(mask2&(1<<i));
            if(b1==0&&b2==0) ans=max(ans,((i+1)&nums[idx])+func(nums,n,idx+1,mask1|(1<<i),mask2,slots));
            else if(b2==0) ans=max(ans,((i+1)&nums[idx])+func(nums,n,idx+1,mask1,mask2|(1<<i),slots));
        }        
        return dp[idx][mask1][mask2]=ans;
    }
    int maximumANDSum(vector<int>& nums, int slots) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return func(nums,n,0,0,0,slots);
    }
};