/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        if(head->next==NULL){
             return head->next;}
        while(fast!=NULL){
            if(fast->next!=NULL){
                fast=fast->next->next;
            }
            else{
                fast=fast->next;
                continue;
            }
            prev=slow;
            slow=slow->next;
        }
        if(slow->next==NULL){
            prev->next=NULL;
        }
        else{
            prev->next=slow->next;
        } 
        return head;
    }
};