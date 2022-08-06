using ll=long long;
class Solution {
public:
    long long minimumReplacement(vector<int>& num) {
        int n=num.size(),right=num[n-1];
        ll res=0,brk;
        if(n==1) return 0;
        for(int i=n-2;i>=0;i--){
            if(right>=num[i]) right=num[i];
            else{
                brk = ((num[i]-1)/right)+1;
                right = num[i]/brk;
                res +=(brk-1);
            } 
        }
        return res;
    }
};