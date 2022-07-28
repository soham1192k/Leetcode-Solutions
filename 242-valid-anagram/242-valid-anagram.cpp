class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        for(auto x:s) mp[x]++;
        for(auto x:t){
            if(mp[x]>=1) mp[x]--;
            else return false;
        }
        if(s.length()==t.length()) return true;
        return false;
    }
};