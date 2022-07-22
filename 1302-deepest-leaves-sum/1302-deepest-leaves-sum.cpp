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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            queue<TreeNode*>nq;
            int sum=0;
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left) nq.push(curr->left);
                if(curr->right) nq.push(curr->right);
            }
            ans=sum;
            q=nq;
        }
        return ans;
    }
};