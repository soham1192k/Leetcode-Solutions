class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            queue<TreeNode*>nq;
            int maxx=INT_MIN;
            while(!q.empty()){
                TreeNode* v=q.front();
                maxx=max(maxx,v->val);
                q.pop();
                if(v->left) nq.push(v->left);
                if(v->right) nq.push(v->right);
            }
            q=nq;
            ans.push_back(maxx);
        }
        return ans;
    }
};