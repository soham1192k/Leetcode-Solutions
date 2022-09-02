struct monotone_deque{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty()&&dq.front()<x) dq.pop_front();
        dq.push_front(x);
    }
    void remove(int x){
        if(!dq.empty()&&dq.back()==x) dq.pop_back();
    }
    int getmax(){
        if(!dq.empty()) return dq.back();
        return 0;
    }
};
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        monotone_deque dq;
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        dq.insert(dp[0]);
        for(int i=1;i<n;i++){
            if(i>=k+1) dq.remove(dp[i-k-1]);
            dp[i]=nums[i]+dq.getmax();
            dq.insert(dp[i]);
        }
        return dp[n-1];
    }
};