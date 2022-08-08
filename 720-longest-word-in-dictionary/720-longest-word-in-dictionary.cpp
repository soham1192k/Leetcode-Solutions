class Node{
public:
    bool flag=false;
    Node* links[26];
    bool containsKey(char ch){
        return (this->links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        this->links[ch-'a']=node;
    }
    Node* get(char ch){
        return this->links[ch-'a'];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string&s){
        Node* node=root;
        for(auto x:s){
            if(!node->containsKey(x)) node->put(x,new Node());
            node=node->get(x);
        }
        node->flag=true;
    }
    bool traverse(string&s){
        Node* node=root;
        for(auto x:s){
            node=node->get(x);
            if(!node->flag) return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* t=new Trie();
        for(auto x:words) t->insert(x);
        string ans="";
        for(auto x:words){
            if(t->traverse(x)){
                if(x.length()>ans.length()) ans=x;
                else if(x.length()==ans.length()) ans=min(ans,x);
            }
        }
        return ans;
    }
};