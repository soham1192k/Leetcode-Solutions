class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int left=0,right=1;
        int maxx=1;
        map<int,int>mp;
        mp[s[0]]++;
        while(right<n){
            if(mp[s[right]]==0){
                mp[s[right]]++;
                maxx=max(maxx,right-left+1);
            }
            else{
                mp[s[right]]++;
                while(left<=right&&mp[s[right]]>1){
                    mp[s[left]]--;
                    left++;
                }
                maxx=max(maxx,right-left+1);
            }   
            right++;
        }
        return maxx;
    }
};