class Node{
public:
    Node* links[2];
    int cnt=0;
    bool containsKey(int x){
        return (this->links[x]!=NULL);
    }
    void put(int x,Node* node){
        this->links[x]=node;
    }
    Node* get(int x){
        return this->links[x];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int x){
        Node* node=root;
        for(int i=30;i>=0;i--){
            int currbit=(x>>i)&1;
            if(!node->containsKey(currbit)) node->put(currbit,new Node());
            node=node->get(currbit);
            node->cnt++;
        }
    }
    int calc(int x,int limit){
        Node* node=root;
        int ans=0;
        if(!node) return ans;
        for(int i=30;i>=0;i--){
            int limit_bit=(limit>>i)&1;
            int no_bit=(x>>i)&1;
            if(limit_bit){
                if(no_bit){
                    if(node->links[1]) ans+=node->links[1]->cnt;
                    node=node->links[0];
                }
                else{
                    if(node->links[0]) ans+=node->links[0]->cnt;
                    node=node->links[1];
                }
            }
            else{
                if(no_bit){
                    node=node->links[1];
                }
                else{
                    node=node->links[0];
                }
            }
            if(!node) break;
        }
        if(node) ans+=node->cnt;
        return ans;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        Trie* t=new Trie();
        int val=0;
        for(auto x:nums){
            val+=t->calc(x,high);
            val-=t->calc(x,low-1);
            t->insert(x);
        }
        return val;
    }
};