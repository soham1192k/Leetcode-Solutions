class Solution {
public:
    int dp[14][1<<14];
    int func(vector<int>&nums1,vector<int>&nums2,int n,int idx,int mask){
        if(idx==n) return 0;
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        int val=1e9;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))) val=min(val,(nums1[idx]^nums2[i])+func(nums1,nums2,n,idx+1,mask|(1<<i)));
        }
        return dp[idx][mask]=val;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        memset(dp,-1,sizeof(dp));
        return func(nums1,nums2,n,0,0);
    }
};