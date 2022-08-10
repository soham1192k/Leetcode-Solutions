class Solution {
public:
    TreeNode* helper(vector<int>&nums,int low,int high){
        if(low>high) return NULL;
        int mid=(low+high)>>1;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,low,mid-1);
        root->right=helper(nums,mid+1,high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};