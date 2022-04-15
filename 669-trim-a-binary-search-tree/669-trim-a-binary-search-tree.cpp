/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;
        // if(root->left==NULL&&root->right==NULL&&!(root->val>=low&&root->val<=high)) return NULL;
        // else if(root->left==NULL&&root->right==NULL) return root;
        if(root->val>=low&&root->val<=high){
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
            return root;
        }
        else if(root->val<low) return trimBST(root->right,low,high);
        else return trimBST(root->left,low,high);
    }
};