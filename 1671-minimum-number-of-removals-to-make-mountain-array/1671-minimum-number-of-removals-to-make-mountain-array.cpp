class Solution {
public:
    vector<int>lis(vector<int>&a){
        vector<int>dp,ret((int)a.size());
        for(int i=0;i<a.size();i++){
            if(dp.empty()||dp.back()<a[i]) {dp.push_back(a[i]);ret[i]=dp.size();}
            else{
                auto itr=lower_bound(dp.begin(),dp.end(),a[i]);
                *itr=a[i];
                ret[i]=itr-dp.begin()+1;
            }
        }
        return ret;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>is=lis(nums);
        reverse(nums.begin(),nums.end());
        vector<int>ds=lis(nums);
        reverse(ds.begin(),ds.end());
        int maxx=0;
        for(int i=1;i<n-1;i++){
            if(is[i]>=2&&ds[i]>=2) maxx=max(maxx,ds[i]+is[i]-1);
        }
        return nums.size()-maxx;
    }
};