class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].length();
        int window_len=len*words.size();
        if(s.length()<window_len) return {};
        vector<string>hold;
        unordered_map<string,int>mp;
        unordered_map<string,int>var;
        for(auto x:words) mp[x]++;
        int idx=0;
        vector<int>ans;
        string curr="";
        for(int i=0;i<window_len;i++){
            curr+=s[i];
            if(i%len==len-1) {hold.push_back(curr);curr="";}
        }
        while(idx<=s.length()-window_len){
            for(auto x:hold) var[x]++;
            bool flag=true;
            for(auto x:var){
                if(x.second!=mp[x.first]) {flag=false;break;}
            }
            if(flag) ans.push_back(idx);
            var.clear();
            for(int i=0;i<hold.size()-1;i++){
                hold[i].erase(0,1);
                hold[i]+=hold[i+1][0];
            }
            hold[hold.size()-1].erase(0,1);
            hold[hold.size()-1]+=s[idx+window_len];
            idx++;
        }
        return ans;
    }
};