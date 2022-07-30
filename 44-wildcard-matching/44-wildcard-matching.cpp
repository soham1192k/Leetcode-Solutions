// class Solution {
// public:
//     int dp[2001][2001];
//     int func(string& s,string& t,int idx_s,int idx_t){
//         if(idx_s<0&&idx_t<0) return 1;
//         if(idx_t<0) return 0;
//         if(idx_s<0){
//             for(int i=0;i<=idx_t;i++){
//                 if(t[i]!='*') return 0;
//             }
//             return 1;
//         }
//         if(dp[idx_s][idx_t]!=-1) return dp[idx_s][idx_t];
//         int ans;
//         if(t[idx_t]=='?') ans=func(s,t,idx_s-1,idx_t-1);
//         else if(t[idx_t]=='*') ans=func(s,t,idx_s,idx_t-1)|func(s,t,idx_s-1,idx_t);
//         else{
//             if(t[idx_t]!=s[idx_s]) ans=0;
//             else ans=func(s,t,idx_s-1,idx_t-1);
//         }
//         return dp[idx_s][idx_t]=ans;
//     }
//     bool isMatch(string s, string t) {
//         memset(dp,-1,sizeof(dp));
//         int n=s.length();
//         int m=t.length();
//         return func(s,t,n-1,m-1);
//     }
// };

class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<int>>& v){
        if(i==s.size()&&j==p.size())
            return true;
        else if(i==s.size()) 
            return (p[j]=='*'&& match(s,p,i,j+1,v));
        else if(j==p.size())
            return false;
        
        if(v[i][j]!=-1) return v[i][j];
        
        if(p[j]=='*')
            return v[i][j]= (match(s,p,i,j+1,v)||match(s,p,i+1,j,v));
        
        if(p[j]=='?'||s[i]==p[j])
            return v[i][j] = match(s,p,i+1,j+1,v);
        
        return false;
    }
    
    bool isMatch(string s, string p) {
       vector<vector<int>> v(s.size(), vector<int>(p.size(), -1));  
       return match(s,p,0,0,v);
    }
};