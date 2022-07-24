class Solution {
public:
    char repeatedCharacter(string s) {
        bool mp[26];
        memset(mp,false,sizeof(mp));
        for(auto x:s){
            if(mp[x-'a']) return x;
            mp[x-'a']=true;
        }
        return '@';
    }
};