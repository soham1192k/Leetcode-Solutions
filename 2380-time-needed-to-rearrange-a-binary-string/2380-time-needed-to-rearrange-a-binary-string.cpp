class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();
        int zero=0,wait=0;
        if(s[0]=='0') zero++;
        int maxx=0;
        for(int i=1;i<n;i++){
            if(s[i]=='1'&&s[i-1]=='1'&&zero>0) wait++;
            else if(s[i]=='0'&&s[i-1]=='0'&&wait>0) wait--;
            if(s[i]=='0') zero++;
            if(s[i]=='1') maxx=max(maxx,wait+zero);
        }
        return maxx;
    }
};