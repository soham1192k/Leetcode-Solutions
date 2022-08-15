class Solution {
public:
    string smallestNumber(string s) {
        string res;
        int n=s.size(),j=0;
        for(int i=0;i<=s.size();i++){
            res.push_back('1'+i);
            if(i==n||s[i]=='I'){
                reverse(res.begin()+j,res.end());
                j=i+1;
            }
        }
        return res;
    }
};