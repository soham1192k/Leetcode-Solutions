class Node{
public:
    Node* links[2];
    bool flag=false;
    bool containsKey(char ch){
        return (this->links[ch-'0']!=NULL);
    }
    void put(char ch,Node* node){
        this->links[ch-'0']=node;
    }
    Node* get(char ch){
        return this->links[ch-'0'];
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string&s){
        Node* node=root;
        for(auto x:s){
            if(!node->containsKey(x)){
                node->put(x,new Node());
            }
            node=node->get(x);
        }
        node->flag=true;
    }
};
class Solution {
public:
    int ans;
    string dectobin(int x){
        string ans="";
        while(x>1){
            ans+=(x%2)+'0';
            x/=2;
        }
        if(x==1) ans+=(x+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(Node* node1,Node* node2,int val){
        if(node1->flag&&node2->flag) ans=max(ans,val);
        bool f=false;
        if(node1->links[0]&&node2->links[1]) {f=true;dfs(node1->links[0],node2->links[1],2*val+1);}
        if(node1->links[1]&&node2->links[0]) {f=true;dfs(node1->links[1],node2->links[0],2*val+1);}
        if(!f&&node1->links[0]&&node2->links[0]) dfs(node1->links[0],node2->links[0],2*val);
        if(!f&&node1->links[1]&&node2->links[1]) dfs(node1->links[1],node2->links[1],2*val);
    }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie* t=new Trie();
        vector<string>hold;
        int maxx=0;
        for(auto x:nums) {string p=dectobin(x);hold.push_back(p);maxx=max(maxx,(int)p.length());}
        for(int i=0;i<hold.size();i++){
            string temp="";
            for(int k=0;k<maxx-(int)hold[i].length();k++) temp+='0';
            temp+=hold[i];
            hold[i]=temp;
        }
        for(auto x:hold){
            t->insert(x);            
        }
        dfs(t->root,t->root,0);
        return ans;
    }
};