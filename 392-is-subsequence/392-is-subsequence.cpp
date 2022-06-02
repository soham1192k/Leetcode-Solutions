class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int ptrs=0,ptrt=0;
        while(ptrt<m){
            if(t[ptrt]==s[ptrs]) {ptrt++;ptrs++;}
            else ptrt++;
        }
        if(ptrs==n) return true;
        return false;
    }
};