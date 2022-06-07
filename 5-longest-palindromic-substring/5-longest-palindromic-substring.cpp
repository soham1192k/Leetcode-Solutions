class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxx=1;
        int starting=0;
        for(int i=1;i<n-1;i++){
            int left=i-1;
            int right=i+1;
            int cnt=0;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--;
                right++;
                cnt+=2;
            }
            if(cnt+1>=maxx){
                maxx=cnt+1;
                starting=left+1;
            }
        }
        for(int i=0;i<=n-2;i++){
            int left=i;
            int right=i+1;
            int cnt=0;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--;
                right++;
                cnt+=2;
            }
            if(cnt>=maxx){
                maxx=cnt;
                starting=left+1;
            }
        }
        return s.substr(starting,maxx);
    }
};