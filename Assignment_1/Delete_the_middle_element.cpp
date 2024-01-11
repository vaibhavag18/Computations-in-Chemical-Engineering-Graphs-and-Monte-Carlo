class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        else{
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = head;
            while(fast and fast->next){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            // now slow will be pointing to middle element;
            // now prev will be pointing to middle-1 th element;
            prev->next = slow->next;
            delete(slow);
            return head;
        }
    }
};