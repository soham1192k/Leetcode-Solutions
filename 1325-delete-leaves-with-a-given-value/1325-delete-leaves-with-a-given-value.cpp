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
    TreeNode* helper(TreeNode* root,int target){
        if(root==NULL) return NULL;
        if(!root->left&&!root->right&&root->val==target) return NULL;
        root->left=helper(root->left,target);
        root->right=helper(root->right,target);
        if(!root->left&&!root->right&&root->val==target) return NULL;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return helper(root,target);
    }
};