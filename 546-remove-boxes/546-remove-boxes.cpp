class Solution {
public:
    int dp[101][101][101];
    int func(vector<int>&boxes,int l,int r,int latch){
        if(l>r) return 0;
        if(l==r) return (latch+1)*(latch+1);
        if(dp[l][r][latch]!=-1) return dp[l][r][latch];
        int ans=(latch+1)*(latch+1)+func(boxes,l+1,r,0);
        for(int i=l+1;i<=r;i++){
            if(boxes[l]==boxes[i]){
                ans=max(ans,func(boxes,l+1,i-1,0)+func(boxes,i,r,latch+1));
            }
        }
        return dp[l][r][latch]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        int n=boxes.size();
        return func(boxes,0,n-1,0);
    }
};