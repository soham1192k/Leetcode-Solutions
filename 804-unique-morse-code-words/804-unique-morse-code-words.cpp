class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>s;
        string curr="";
        for(auto x:words){
            curr="";
            for(auto y:x) curr+=arr[y-'a'];
            s.insert(curr);
        }
        return s.size();
    }
};