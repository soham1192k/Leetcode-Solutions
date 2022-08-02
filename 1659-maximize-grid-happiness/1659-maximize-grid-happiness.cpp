class Solution {
public:
    int dp[26][7][7][(1<<6)][(1<<6)];
    int update_cost(int n,int m,int i,int j,int imask,int emask,int diff){
        int ret=0;
        if(j>0&&(imask&1)) ret+=diff-30;
        if(i>0&&(imask&(1<<(m-1)))) ret+=diff-30;
        if(j>0&&(emask&1)) ret+=diff+20;
        if(i>0&&(emask&(1<<(m-1)))) ret+=diff+20;
        return ret;
    }
    int func(int n,int m,int idx,int icnt,int ecnt,int imask,int emask){
        int i=idx/m,j=idx%m;
        if(i==n) return 0;
        if(dp[idx][icnt][ecnt][imask][emask]!=-1) return dp[idx][icnt][ecnt][imask][emask];
        int n_imask=(imask<<1)&63,n_emask=(emask<<1)&63;
        int ans;
        ans=func(n,m,idx+1,icnt,ecnt,n_imask,n_emask);
        int val;
        if(icnt>=1){
            val=120+update_cost(n,m,i,j,imask,emask,-30);
            ans=max(ans,val+func(n,m,idx+1,icnt-1,ecnt,n_imask+1,n_emask));
        }
        if(ecnt>=1){
            val=40+update_cost(n,m,i,j,imask,emask,20);
            ans=max(ans,val+func(n,m,idx+1,icnt,ecnt-1,n_imask,n_emask+1));
        }
        return dp[idx][icnt][ecnt][imask][emask]=ans;
    }
    int getMaxGridHappiness(int n, int m, int icnt, int ecnt) {
        memset(dp,-1,sizeof(dp));
        return func(n,m,0,icnt,ecnt,0,0);
    }
};