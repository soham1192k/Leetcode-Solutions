class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int i,j,n,m;
        string ans="";
        for(auto x:dictionary){
            i=0,j=0;
            n=s.length();m=x.length();
            while(i<n){
                if(s[i]==x[j]) j++;
                i++;
            }
            if(j==m){
                if(x.length()>ans.length()) ans=x;
                else if(x.length()==ans.length()) ans=min(ans,x);
            }
        }
        return ans;
    }
};