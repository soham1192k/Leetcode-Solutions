class Solution {
public:
    bool match(string&s,string&t){
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            if(s[i]==t[i]||t[i]=='?') ;
            else return false;
        }
        return true;
    }
    bool allWild(string& s){
        for(auto x:s){
            if(x!='?') return false;
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n=target.length();
        int m=stamp.length();
        bool flag=true;
        string str;
        vector<int>ans;
        while(flag){
            flag=false;
            for(int i=0;i<n-m+1;i++){
                str=target.substr(i,m);
                if(allWild(str)) continue;
                if(match(stamp,str)){
                    flag=true;
                    ans.push_back(i);
                    for(int j=i;j<i+m;j++) target[j]='?';
                }
            }
        }
        if(ans.size()>10*n||!allWild(target)) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};