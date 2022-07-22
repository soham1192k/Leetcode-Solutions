class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ptr=new ListNode(0);
        ListNode* new_head=ptr;
        ListNode* tmp=head;
        while(tmp!=NULL){
            if(tmp->val<x){
                ptr->next=new ListNode(tmp->val);
                ptr=ptr->next;
            }
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp!=NULL){
            if(tmp->val>=x){
                ptr->next=new ListNode(tmp->val);
                ptr=ptr->next;
            }
            tmp=tmp->next;
        }
        return new_head->next;
    }
};