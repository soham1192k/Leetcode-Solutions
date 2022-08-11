class Solution {
public:
    int dp[1<<14][8];
    int func(int mask,int n,int op,vector<int>&nums){
        if(op==n/2+1) return 0;
        if(dp[mask][op]!=-1) return dp[mask][op];
        int ans=0;
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                for(int j=i+1;j<n;j++){
                    if((mask>>j)&1){
                        int n_mask=mask^(1<<i);
                        n_mask^=(1<<j);
                        ans=max(ans,op*__gcd(nums[i],nums[j])+func(n_mask,n,op+1,nums));
                    }
                }
            }
        }
        return dp[mask][op]=ans;
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return func((1<<n)-1,n,1,nums);
    }
};