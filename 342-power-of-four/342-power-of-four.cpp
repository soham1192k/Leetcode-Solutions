class Solution {
public:
    bool isPowerOfFour(int n) {
        if(__builtin_popcount(n)!=1) return false;
        for(int i=0;i<=30;i+=2){
            if((n>>i)&1) return true;
        }
        return false;
    }
};




