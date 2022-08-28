class Node{
public:
    int key,val;
    Node* prev,*next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->prev=this->next=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    Node* head,*tail;
    int cap;
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* curr=mp[key];
        int val=curr->val;
        mp.erase(key);
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        delete curr;
        curr=new Node(key,val);
        curr->next=head->next;
        head->next=curr;
        curr->prev=head;
        curr->next->prev=curr;
        mp[key]=curr;
        return val;
    }
    void put(int key, int value) {
        Node* curr;
        if(mp.size()<cap){
            if(mp.find(key)!=mp.end()){
                curr=mp[key];
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
                mp.erase(key);
            }
            curr=new Node(key,value);
            curr->next=head->next;
            head->next=curr;
            curr->prev=head;
            curr->next->prev=curr;
            mp[key]=curr;
            Node* temp=tail;
        }
        else{
            if(mp.find(key)!=mp.end()){
                curr=mp[key];
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
                mp.erase(key);
            }
            else{
                curr=tail->prev;
                mp.erase(curr->key);
                tail->prev->prev->next=tail;
                tail->prev=tail->prev->prev;
                delete curr;
            }
            curr=new Node(key,value);
            curr->next=head->next;
            head->next=curr;
            curr->prev=head;
            curr->next->prev=curr;
            mp[key]=curr;
        }
    }
};