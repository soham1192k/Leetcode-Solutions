using ll=long long;
class Solution {
public:
    int ans;
    void merge(vector<int>&nums,int low,int mid,int high){
        vector<ll>left,right;
        for(int i=low;i<=mid;i++) left.push_back(nums[i]);
        for(int i=mid+1;i<=high;i++) right.push_back(nums[i]);
        int idx=low,l_ptr=0,r_ptr=0;
        int itr=0;
        for(int i=mid+1;i<=high;i++){
            while(itr<left.size()&&left[itr]<=2*right[i-mid-1]) itr++; 
            ans+=left.size()-itr;
        }
        while(l_ptr<left.size()&&r_ptr<right.size()){
            if(left[l_ptr]<right[r_ptr]){
                nums[idx++]=left[l_ptr++];
            }
            else{
                nums[idx++]=right[r_ptr++];
            }
        }
        while(l_ptr<left.size()){
            nums[idx++]=left[l_ptr++];
        }
        while(r_ptr<right.size()){
            nums[idx++]=right[r_ptr++];
        }
    }
    void mergesort(vector<int>&nums,int low,int high){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return ans;
    }
};