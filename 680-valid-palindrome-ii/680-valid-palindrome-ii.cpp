class Solution {
public:
    bool check(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            else {i++;j--;}
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(check(s,i,j-1)) j--;
                else if(check(s,i+1,j)) i++;
                else return false;
            }
            else {i++;j--;}
        }
        return true;
    }
};