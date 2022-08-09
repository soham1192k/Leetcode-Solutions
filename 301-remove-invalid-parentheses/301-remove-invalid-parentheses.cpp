class Solution {
public:
    set<string>ans;
    bool ok(string& s){
        int curr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') curr++;
            else if(s[i]==')') curr--;
            if(curr<0) return false;
        }
        if(curr!=0) return false;
        return true;
    }
    void func(string& s,int idx,string& hold){
        if(idx==s.length()){
            if(ok(hold)){
                if(ans.empty()) ans.insert(hold);
                else{
                    int currlength=ans.begin()->length();
                    if(hold.length()>currlength){
                        ans.clear();
                        ans.insert(hold);
                    }
                    else if(hold.length()==currlength){
                        ans.insert(hold);
                    }
                }
            }
            return;
        }
        if(s[idx]=='('||s[idx]==')') func(s,idx+1,hold);
        hold+=s[idx];
        func(s,idx+1,hold);
        hold.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        string hold="";
        func(s,0,hold);
        vector<string>h;
        for(auto x:ans) h.push_back(x);
        return h;
    }
};