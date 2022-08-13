class Solution {
public:
    void merge(vector<pair<int,int>>&v,int left,int mid,int right,vector<int>&count) {
        vector<pair<int,int>>tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        while (i<=mid&&j<=right){
            if(v[i].first<=v[j].first) tmp[k++]=v[j++];
            else{
                count[v[i].second]+=right-j+1;
                tmp[k++]=v[i++];
            }
        }
        while(i<=mid) tmp[k++]=v[i++];
        while(j<=right) tmp[k++]=v[j++];
        for(int i=left;i<=right;i++) v[i]=tmp[i-left];
    }  
    void mergesort(vector<pair<int,int>>&nums,int low,int high,vector<int>&ans){
        if(low>=high) return;
        int mid=(low+high)>>1;
        mergesort(nums,low,mid,ans);
        mergesort(nums,mid+1,high,ans);
        merge(nums,low,mid,high,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>hold;
        for(int i=0;i<n;i++) hold.push_back({nums[i],i});
        mergesort(hold,0,n-1,ans);
        return ans;
    }
};