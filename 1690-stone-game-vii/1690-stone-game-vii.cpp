class Solution {
public:
    vector<int>pre;
    int dp[1001][1001];
    int func(vector<int>&nums,int low,int high){
        if(low>high) return 0;
        if(dp[low][high]!=-1) return dp[low][high];
        int left=pre[high]-pre[low];
        int right=0;
        if(high-1>=0) right+=pre[high-1];
        if(low-1>=0) right-=pre[low-1];
        return dp[low][high]=max(left-func(nums,low+1,high),right-func(nums,low,high-1));
    }
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n=stones.size();
        pre.resize(n);
        pre[0]=stones[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+stones[i];
        return func(stones,0,n-1);
    }
};