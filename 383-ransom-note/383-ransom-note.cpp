class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mp;
        for(auto x:magazine) mp[x]++;
        for(auto x:ransomNote){
            if(mp[x]>=1) mp[x]--;
            else return false;
        }
        return true;
    }
};