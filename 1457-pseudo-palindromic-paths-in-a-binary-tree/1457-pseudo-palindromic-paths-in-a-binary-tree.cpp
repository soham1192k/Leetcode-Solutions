class Solution {
public:
    void dfs(TreeNode* root,int mask,int& ans){
        if(!root) return;
        mask^=(1<<(root->val-1));
        if(!root->left&&!root->right&&__builtin_popcount(mask)<=1) ans++;
        dfs(root->left,mask,ans);
        dfs(root->right,mask,ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        dfs(root,0,ans);
        return ans;
    }
};