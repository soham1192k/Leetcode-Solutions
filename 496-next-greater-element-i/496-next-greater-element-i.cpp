class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums2[i]]=i;
        vector<int>ans(n,-1);
        stack<int>st;
        st.push(nums2[n-1]);
        ans[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&st.top()<nums2[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int>fin;
        for(auto x:nums1) fin.push_back(ans[mp[x]]);
        return fin;
    }
};