class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length();
        int absent=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A') absent++;
        }
        for(int i=0;i<n-2;i++){
            if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L') return false;
        }
        if(absent<2) return true;
        return false;
    }
};