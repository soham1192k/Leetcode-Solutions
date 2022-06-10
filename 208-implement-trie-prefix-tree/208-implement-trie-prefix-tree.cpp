struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);   
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        Node* node=root;
        for(auto x:word){
            if(!node->containsKey(x)){
                node->put(x,new Node());
            }
            node=node->get(x);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node=root;
        for(auto x:word){
            if(!node->containsKey(x)) return false;
            node=node->get(x);
        }
        return node->flag;
    }
    bool startsWith(string prefix) {
        Node* node=root;
        for(auto x:prefix){
            if(!node->containsKey(x)) return false;
            node=node->get(x);
        }
        return true;
    }
};

