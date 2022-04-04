class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        for(int i=1;i<=k-1;i++) ptr1=ptr1->next;
        while(ptr1->next!=NULL) {ptr1=ptr1->next;ptr2=ptr2->next;}
        ptr1=head;
        for(int i=1;i<=k-1;i++) ptr1=ptr1->next;
        swap(ptr1->val,ptr2->val);
        return head;
    } 
};