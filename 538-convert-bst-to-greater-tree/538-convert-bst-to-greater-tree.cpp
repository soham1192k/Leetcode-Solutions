class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        root->right=convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        root->left=convertBST(root->left);
        return root;
    }
};