class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>tmp;
        for(auto x:nums) tmp.push_back(x);
        for(auto x:nums) tmp.push_back(x);
        stack<int>st;
        vector<int>ans(n);
        for(int i=2*n-1;i>=n;i--) st.push(tmp[i]);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=tmp[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(tmp[i]);
        }
        return ans;
    }
};