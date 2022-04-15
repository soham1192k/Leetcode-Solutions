class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;
        int v=root->val;
        if(v>=low&&v<=high){
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
            return root;
        }
        else if(v<low) return trimBST(root->right,low,high);
        else return trimBST(root->left,low,high);
    }
};