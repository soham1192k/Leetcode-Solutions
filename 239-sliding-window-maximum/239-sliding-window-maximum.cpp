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
        else return -1;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        monotone_deque dq;
        for(int i=0;i<k;i++) dq.insert(nums[i]);
        vector<int>ans;
        ans.push_back(dq.getmax());
        for(int i=k;i<n;i++){
            dq.remove(nums[i-k]);
            dq.insert(nums[i]);
            ans.push_back(dq.getmax());
        }
        return ans;
    }
};