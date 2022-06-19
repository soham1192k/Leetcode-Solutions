class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        if(!root->left&&!root->right&&root->val!=1) return NULL;
        root->left=helper(root->left);
        root->right=helper(root->right);
        if(!root->left&&!root->right&&root->val!=1) return NULL;
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};