class Solution {
public:
    int dp[101];
    int func(vector<int>&a,int idx){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(func(a,idx-1),a[idx]+func(a,idx-2));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        vector<int>t1,t2;
        for(int i=0;i<n-1;i++) t1.push_back(nums[i]);
        for(int i=1;i<n;i++) t2.push_back(nums[i]);
        int val1=func(t1,n-2);
        memset(dp,-1,sizeof(dp));
        int val2=func(t2,n-2);
        return max(val1,val2);
    }
};