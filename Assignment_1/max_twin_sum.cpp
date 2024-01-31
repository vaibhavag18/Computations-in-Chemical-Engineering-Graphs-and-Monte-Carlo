class Solution {
public:
    int pairSum(ListNode* head) {
        // firstly we will reverse nodes from n/2 index onwards;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow will be pointing to n/2 th index;
        // Let's now reverse the LL from n/2 onwards
        ListNode* prev_ptr = NULL;
        ListNode* curr_ptr = slow;
        while(curr_ptr){
            ListNode* next_ptr = curr_ptr->next;
            curr_ptr->next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        //now prev_ptr will be pointing to head of the reversed nodes;
        // take two pointers one on starting of ll and one at the end
        ListNode* temp1 = head;
        ListNode* temp2 = prev_ptr;
        int max_sum = -1;
        while(temp2){
            int sum = temp1->val + temp2->val;
            max_sum = max(sum,max_sum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return max_sum;
    }
};