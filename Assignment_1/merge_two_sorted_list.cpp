class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp3 = new ListNode();
        ListNode* dummy_head = temp3;
        while(temp1 != NULL and temp2 != NULL){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp3 = temp3->next;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp3 = temp3->next;
                temp2 = temp2->next;
            }
        }
        if(temp1 != NULL) temp3->next = temp1;
        if(temp2 != NULL) temp3->next = temp2;
        return dummy_head->next;// because if have initialized temp3 with a dummy node;        
    }
};