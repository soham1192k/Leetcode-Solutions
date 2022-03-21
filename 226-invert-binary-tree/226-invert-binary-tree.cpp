class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left==NULL&&root->right==NULL) return root;
        TreeNode* a=invertTree(root->right);
        TreeNode* b=invertTree(root->left);
        root->left=a;
        root->right=b;
        return root;
    }
};