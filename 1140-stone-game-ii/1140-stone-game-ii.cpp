class Solution {
public:
    int dp[101][129];
    int func(vector<int>&p,int n,int i,int m){
        if(i==n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=INT_MIN,sum=0;
        for(int j=i;j<n&&j-i+1<=2*m;j++){
            sum+=p[j];
            ans=max(ans,sum-func(p,n,j+1,max(m,j-i+1)));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int sum=0;
        for(auto x:piles) sum+=x;
        memset(dp,-1,sizeof(dp));
        return (sum+func(piles,n,0,1))/2;
    }
};
