class Solution {
public:
    int dp[101];
    int func(string&s,int idx){
        if(idx<0) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        if(s[idx]!='0') ans+=func(s,idx-1);
        if(idx>=1){
            if(s[idx-1]=='1') ans+=func(s,idx-2);
            else if(s[idx-1]=='2'){
                if(s[idx]>='0'&&s[idx]<='6') ans+=func(s,idx-2);
            }
        }
        return dp[idx]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return func(s,s.length()-1);   
    }
};