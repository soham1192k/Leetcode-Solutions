class Solution {
public:
    int helper(TreeNode* root,int maxx){
        if(!root) return 0;
        int ans=0;
        if(root->val>=maxx) ans=1;
        ans+=helper(root->left,max(maxx,root->val))+helper(root->right,max(maxx,root->val));
        return ans;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return helper(root,-1e4-1);
    }
};