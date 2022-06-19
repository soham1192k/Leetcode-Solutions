class Solution {
public:
    map<pair<TreeNode*,int>,int>mp;
    int helper(TreeNode* root,int par_robbed){
        if(!root) return 0;
        if(mp.find({root,par_robbed})!=mp.end()) return mp[{root,par_robbed}];
        int ans=0;
        if(par_robbed==0) ans=root->val+helper(root->left,1)+helper(root->right,1);
        ans=max(ans,helper(root->left,0)+helper(root->right,0));
        return mp[{root,par_robbed}]=ans;
    }
    int rob(TreeNode* root) {
        return helper(root,0);
    }
};