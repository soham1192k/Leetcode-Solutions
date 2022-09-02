class Solution {
public:
    bool check(unordered_map<char,int>&mp,unordered_map<char,int>&hold){
        for(auto x:mp){
            if(x.second>hold[x.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.length();
        unordered_map<char,int>mp,hold;
        for(auto x:t) mp[x]++;
        int l=0,r=0;
        int minn=1e9,idx=-1;
        while(r<n){
            while(r<n&&check(mp,hold)==false){
                hold[s[r]]++;
                r++;
            }
            if(check(mp,hold)&&minn>r-l){
                minn=r-l;
                idx=l;
            }
            bool f=false;
            while(l<=r&&check(mp,hold)){
                hold[s[l]]--;
                l++;
                f=true;
            }
            if(f&&minn>r-l+1){
                minn=r-l+1;
                idx=l-1;
            }
        }
        if(idx==-1) return "";
        return s.substr(idx,minn);
    }
};