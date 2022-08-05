class Solution {
public:
    int dp[501][501];
    int func(vector<int>&piles,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool alice_chance=false;
        if((j-i)%2) alice_chance=true;
        int ans=0;
        if(alice_chance) ans=max(piles[i]+func(piles,i+1,j),piles[j]+func(piles,i,j-1));
        else ans=min(-piles[i]+func(piles,i+1,j),-piles[j]+func(piles,i,j-1));
        return dp[i][j]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int val=func(piles,0,n-1);
        if(val>0) return true;
        return false;
    }
};