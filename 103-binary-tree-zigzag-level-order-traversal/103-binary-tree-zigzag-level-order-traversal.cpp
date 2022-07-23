class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        bool flag=0;
        vector<vector<int>>ans;
        vector<int>hold;
        while(!q.empty()){
            queue<TreeNode*>nq;
            while(!q.empty()){
                TreeNode* curr=q.front();
                hold.push_back(curr->val);
                q.pop();
                if(curr->left) nq.push(curr->left);
                if(curr->right) nq.push(curr->right);
            }
            q=nq;
            if(flag) reverse(hold.begin(),hold.end()); 
            ans.push_back(hold);
            hold.clear();
            flag^=1;
        }
        return ans;
    }
};