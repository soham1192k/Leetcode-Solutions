class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string>hold;
        for(int i=1;;i*=2){
            if(i>1e9) break;
            string curr=to_string(i);
            sort(curr.begin(),curr.end());
            hold.push_back(curr);
        }
        string check=to_string(n);
        sort(check.begin(),check.end());
        for(auto x:hold){
            if(x==check) return true;
        }
        return false;
    }
};