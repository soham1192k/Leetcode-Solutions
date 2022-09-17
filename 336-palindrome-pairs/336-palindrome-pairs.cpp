class Solution {
public:
    map<string,bool> sm;
    bool pal(string &s){
        if(sm.find(s) != sm.end()) return sm[s];
        int n = s.length();
        if(n == 0) return sm[s] = true;
        for(int i = 0;i <= n/2;i++){
            if( s[i] != s[(n - i) - 1] ) return sm[s] = false;
        }
        return sm[s] = true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> m; 
        for(int i=0;i<words.size();i++){
            string s = words[i];
            reverse(s.begin(),s.end());
            m[s] = i;
        }
        if(m.find("") != m.end()) {
            for(int i = 0; i < words.size(); i++) {
                if(i == m[""]) continue;
                if(pal(words[i])){ ans.push_back({i, m[""]});}
            }
        }
        for(int i=0;i<words.size();i++){
            string r = words[i];
            string l = "";
            for(int j = 0; j < words[i].length() ; j++){
                l.push_back(words[i][j]);
                r.erase(0,1);
                if(m.find(l) != m.end() && pal(r) && m[l] != i) ans.push_back({i, m[l]});
                if(m.find(r) != m.end() && pal(l) && m[r] != i) ans.push_back({m[r], i});
            }
        }
        return ans;
    }
};