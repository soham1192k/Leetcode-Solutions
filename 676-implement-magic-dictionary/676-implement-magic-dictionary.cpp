class MagicDictionary {
public:
    vector<string>hold;
    MagicDictionary() {
        
    }   
    void buildDict(vector<string> dictionary) {
        for(auto x:dictionary) hold.push_back(x);
    }
    bool search(string s) {
        int n=s.length();
        int cnt;
        for(auto x:hold){
            if(x.length()!=n) continue;
            cnt=0;
            for(int i=0;i<n;i++){
                if(x[i]!=s[i]) cnt++;
            }
            if(cnt==1) return true;
        }
        return false;
    }
};