class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            queue<Node*>nq;
            Node* prev=NULL;
            while(!q.empty()){
                Node* v=q.front();
                q.pop();
                if(v->left) nq.push(v->left);
                if(v->right) nq.push(v->right);
                if(prev) prev->next=v;
                prev=v;
            }
            q=nq;
        }
        return root;
    }
};