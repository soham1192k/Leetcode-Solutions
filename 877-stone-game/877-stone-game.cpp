class Solution {
public:
    int dp[501][501];
    int func(vector<int>&piles,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(piles[i]-func(piles,i+1,j),piles[j]-func(piles,i,j-1));
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        if(func(piles,0,n-1)>0) return true;
        return false;
    }
};