class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode *fast=head,*mid=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            mid=mid->next;
        }
        if(mid->next==NULL){
            delete mid;
            head->next = NULL;
            return head;
        }
        swap(mid->val,mid->next->val);
        ListNode *temp = mid->next;
        mid->next = temp->next;
        delete temp;
        return head;
    }
};
