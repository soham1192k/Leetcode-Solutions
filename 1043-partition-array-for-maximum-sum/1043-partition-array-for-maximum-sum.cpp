class Solution {
public:
    int dp[505];
    int func(vector<int>&arr,int n,int k,int idx){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        int maxx=-1;
        for(int i=idx-1;i>=max(-1,idx-k);i--){
            maxx=max(maxx,arr[i+1]);
            ans=max(ans,func(arr,n,k,i)+(idx-i)*maxx);
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return func(arr,n,k,n-1);
    }
};


