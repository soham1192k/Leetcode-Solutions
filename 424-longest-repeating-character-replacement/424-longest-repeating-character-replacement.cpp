class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int left=0;
        unordered_map<char,int>mp;
        int maxx,ans=1,i;
        for(i=0;i<n;i++){
            mp[s[i]-'A']++;
            maxx=0;
            for(int j=0;j<26;j++) maxx=max(maxx,mp[j]);
            if(i-left+1-maxx>k){
                while(true){
                    maxx=0;
                    mp[s[left++]-'A']--;
                    for(int j=0;j<26;j++) maxx=max(maxx,mp[j]);
                    if(i-left+1-maxx<=k) break;
                }
            }
            else ans=max(ans,i-left+1);
        }
        return ans;
    }
};