class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            queue<TreeNode*>nq;
            int last=-101;
            while(!q.empty()){
                TreeNode* v=q.front();
                q.pop();
                if(v->left) nq.push(v->left);
                if(v->right) nq.push(v->right);
                last=v->val;
            }
            q=nq;
            ans.push_back(last);
        }
        return ans;
    }
};