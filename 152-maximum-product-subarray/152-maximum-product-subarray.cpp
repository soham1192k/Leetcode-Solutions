class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxx[n],minn[n];
        maxx[0]=minn[0]=nums[0];
        for(int i=1;i<n;i++){
            maxx[i]=max({nums[i],minn[i-1]*nums[i],maxx[i-1]*nums[i]});
            minn[i]=min({nums[i],maxx[i-1]*nums[i],minn[i-1]*nums[i]});
        }
        int m=-11;
        for(int i=0;i<n;i++) m=max(m,maxx[i]);
        return m;
    }
};