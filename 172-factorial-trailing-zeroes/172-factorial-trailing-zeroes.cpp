class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        int ptr=5;
        while(ptr<=n){
            ans+=n/ptr;
            ptr*=5;
        }
        return ans;
    }
};