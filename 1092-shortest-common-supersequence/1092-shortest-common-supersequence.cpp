class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m;
        string ans="";
        while(i>0&&j>0){
            if(s[i-1]==t[j-1]) {ans+=s[i-1];i--;j--;}
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s[i-1];
                i--;
            }
            else{
                ans+=t[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=s[i-1];
            i--;
        }
        while(j>0){
            ans+=t[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};