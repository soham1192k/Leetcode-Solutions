class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* tmp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return tmp;
    }
};