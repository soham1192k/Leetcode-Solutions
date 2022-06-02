class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        int cnt[n];
        for(int i=0;i<n;i++) {cnt[i]=1;dp[i]=1;}
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    else if(1+dp[j]==dp[i]) cnt[i]+=cnt[j];
                }
            }
        }
        int maxx=0,sum=0;
        for(int i=0;i<n;i++) maxx=max(maxx,dp[i]);
        for(int i=0;i<n;i++){
            if(dp[i]==maxx) sum+=cnt[i];
        }
        return sum;
    }
};


