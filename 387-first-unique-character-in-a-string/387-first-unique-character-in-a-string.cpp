class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        int present[26];
        memset(present,0,sizeof(present));
        for(int i=0;i<n;i++) present[s[i]-'a']++;           
        for(int i=0;i<n;i++){
            if(present[s[i]-'a']==1) return i;
        }
        return -1;
    }
};