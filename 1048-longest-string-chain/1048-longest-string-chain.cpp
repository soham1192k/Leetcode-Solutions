class Solution {
public:
    static bool cmp(string&s,string&t){
        if(s.length()==t.length()) return s<t;
        return s.length()<t.length();
    }
    bool check(string&s,string&t){
        if(s.length()!=t.length()+1) return false;
        int first=0,second=0;
        while(first<s.length()){
            if(s[first]==t[second]){
                first++;second++;
            }
            else{
                first++;
            }
        }
        if(first==s.length()&&second==t.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])) dp[i]=max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};