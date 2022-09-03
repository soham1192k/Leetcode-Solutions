class Solution {
public:
    vector<int>ans;
    void func(int idx,int curr,int prev,int n,int k){
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        if(prev==-1){
            for(int i=1;i<=9;i++) func(idx+1,curr*10+i,i,n,k);
        }
        else{
            if(prev-k>=0) func(idx+1,curr*10+prev-k,prev-k,n,k);
            if(k!=0&&prev+k<=9) func(idx+1,curr*10+prev+k,prev+k,n,k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        func(0,0,-1,n,k);
        return ans;
    }
};