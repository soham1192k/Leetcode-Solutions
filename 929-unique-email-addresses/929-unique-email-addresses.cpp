class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,bool>mp;
        string s;int idx;
        for(int i=0;i<emails.size();i++){
            s="";
            idx=-1;
            for(int j=0;j<emails[i].length();j++){
                if(emails[i][j]=='+') break;
                if(emails[i][j]=='.') continue;
                if(emails[i][j]=='@') break;
                s+=emails[i][j];
            }
            for(int j=0;j<emails[i].length();j++){
                if(emails[i][j]=='@') {idx=j;break;}
            }
            for(int j=idx;j<emails[i].length();j++) s+=emails[i][j];
            mp[s]=true;
        }
        int cnt=0;
        for(auto x:mp) cnt++;
        return cnt;
    }
};