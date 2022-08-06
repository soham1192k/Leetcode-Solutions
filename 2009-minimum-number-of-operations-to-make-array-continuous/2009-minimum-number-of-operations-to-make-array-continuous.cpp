class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        set<int>s;
        for(auto x:nums) s.insert(x);
        for(auto x:s) a.push_back(x);
        int p=a.size();
        int left=0,right=0;
        int minn=1e9;
        while(right<p){
            while(right<p&&a[right]-a[left]<=n-1) right++;
            minn=min(minn,n-right+left);
            if(right<p){
                while(left<=right&&a[right]-a[left]>n-1) left++;
            }
        }
        minn=min(minn,n-right+left);
        return minn;
    }
};
