class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=0;i<=30;i++){
            int b1=(left&(1<<i));
            int b2=(right&(1<<i));
            if(b1==0||b2==0) continue;
            if(right-left+1<=(1<<i)) ans+=(1<<i);
        }
        return ans;
    }
};