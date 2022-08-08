using pii=pair<pair<int,int>,int>;
class Node{
public:
    Node* links[2];
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
        }
    }
    int maxxor(int x){
        Node* node=root;
        if(node->links[0]==NULL&&node->links[1]==NULL) return -1;
        int ans=0;
        for(int i=30;i>=0;i--){
            int currbit=(x>>i)&1;
            if(node->links[currbit^1]!=NULL){
                ans+=(1<<i);
                node=node->links[currbit^1];
            }
            else node=node->links[currbit];
        }
        return ans;
    }
};
class Solution {
public:
    static bool cmp(pii&a,pii&b){
        return a.first.second<b.first.second;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pii>hold;
        for(int i=0;i<queries.size();i++) hold.push_back({{queries[i][0],queries[i][1]},i});
        sort(nums.begin(),nums.end());
        sort(hold.begin(),hold.end(),cmp);
        int idx=0;
        Trie* t=new Trie();
        vector<int>ans(hold.size());
        for(int i=0;i<hold.size();i++){
            while(idx<nums.size()&&nums[idx]<=hold[i].first.second) t->insert(nums[idx++]);
            ans[hold[i].second]=t->maxxor(hold[i].first.first);
        }
        return ans;
    }
};