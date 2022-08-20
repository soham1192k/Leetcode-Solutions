class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();
        int cnt=0;
        while(true){
            bool flag=false;
            for(int i=1;i<n;i++){
                if(s[i]=='1'&&s[i-1]=='0'){
                    swap(s[i-1],s[i]);
                    flag=true;
                    i++;
                }
            }
            if(flag) cnt++;
            else break;
        }
        return cnt;
    }
};