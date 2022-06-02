class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>d(n+1,1e9);
        d[0]=-1e9;
        for(int i=0;i<n;i++){
            int j=upper_bound(d.begin(),d.end(),nums[i])-d.begin();
            if(d[j-1]<nums[i]&&nums[i]<d[j]) d[j]=nums[i];
        }
        int ans=0;
        for(int i=n;i>=0;i--){
            if(d[i]<1e9) {ans=i;break;}
        } 
        return ans;
    }
};