class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0;
        int sum=helper(root->left)+helper(root->right);
        if(root->val%2==0){
            if(root->left){
                if(root->left->left) sum+=root->left->left->val;
                if(root->left->right) sum+=root->left->right->val;
            }
            if(root->right){
                if(root->right->left) sum+=root->right->left->val;
                if(root->right->right) sum+=root->right->right->val;
            }
        }
        return sum;
    }   
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        return helper(root);
    }
};