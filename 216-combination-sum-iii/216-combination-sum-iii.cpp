class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void func(int k,int mask,int rem,int idx){
        if(__builtin_popcount(mask)==k){
            if(rem==0){
                temp.clear();
                for(int i=0;i<=8;i++){
                    if(mask&(1<<i)) temp.push_back(i+1);
                }
                ans.push_back(temp);
            }
            return;
        }
        if(idx<0) return;
        func(k,mask,rem,idx-1);
        if(!(mask&(1<<idx))) func(k,mask|(1<<idx),rem-idx-1,idx-1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        func(k,0,n,8);
        return ans;
    }
};