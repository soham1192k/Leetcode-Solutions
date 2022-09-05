class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*>q;
        q.push(root);
        vector<int>hold;
        while(!q.empty()){
            queue<Node*>nq;
            hold.clear();
            while(!q.empty()){
                Node* curr=q.front();
                q.pop();
                hold.push_back(curr->val);
                for(Node* node:curr->children) nq.push(node);
            }
            q=nq;
            ans.push_back(hold);
        }
        return ans;
    }
};