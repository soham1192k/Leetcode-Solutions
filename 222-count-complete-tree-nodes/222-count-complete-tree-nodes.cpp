class Solution {
public:
    bool ok(TreeNode* root,int mid,int d){
        mid--;
        TreeNode* temp=root;
        for(int i=d-1;i>=0;i--){
            int currbit=(mid>>i)&1;
            if(currbit) temp=temp->right;
            else temp=temp->left;
        }
        return (temp!=NULL);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int d=0;
        TreeNode* temp=root;
        while(temp->left){
            d++;
            temp=temp->left;
        }
        int low=1,high=(1<<d),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ok(root,mid,d)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans+(1<<d)-1;
    }
};