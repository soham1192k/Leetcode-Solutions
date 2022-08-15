class Solution {
public:
    int ar[11];
    int dp[11][1024][2][2];
    int func(int idx,int mask,int n,int flexible,int seen){
        if(idx==n){
            if(__builtin_popcount(mask)!=0) return 1;
            return 0;
        }
        if(dp[idx][mask][flexible][seen]!=-1) return dp[idx][mask][flexible][seen];
        int ans=0,currbit;
        if(!seen){
            if(flexible){
                ans+=func(idx+1,mask,n,flexible,false);
                //1 to 9
                for(int i=1;i<=9;i++){
                    currbit=(mask>>i)&1;
                    if(currbit==0) ans+=func(idx+1,mask|(1<<i),n,flexible,true);
                }
            }
            else{
                if(ar[idx]==0) ans+=func(idx+1,mask,n,flexible,false);
                else ans+=func(idx+1,mask,n,true,false);
                //1 to ar[idx]
                for(int i=1;i<ar[idx];i++){
                    currbit=(mask>>i)&1;
                    if(currbit==0) ans+=func(idx+1,mask|(1<<i),n,true,true);
                }
                currbit=(mask>>ar[idx])&1;
                if(currbit==0) ans+=func(idx+1,mask|(1<<ar[idx]),n,false,true);
            } 
        }
        else{
            if(flexible){
                //0 to 9
                for(int i=0;i<=9;i++){
                    currbit=(mask>>i)&1;
                    if(currbit==0) ans+=func(idx+1,mask|(1<<i),n,flexible,seen);
                }
            }
            else{
                //0 to ar[idx]
                for(int i=0;i<ar[idx];i++){
                    currbit=(mask>>i)&1;
                    if(currbit==0) ans+=func(idx+1,mask|(1<<i),n,true,seen);
                }
                currbit=(mask>>ar[idx])&1;
                if(currbit==0) ans+=func(idx+1,mask|(1<<ar[idx]),n,false,seen);
            }
        }
        return dp[idx][mask][flexible][seen]=ans;
    }
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        for(int i=0;i<s.length();i++) ar[i]=s[i]-'0';
        memset(dp,-1,sizeof(dp));
        return func(0,0,s.length(),false,false);
    }
};