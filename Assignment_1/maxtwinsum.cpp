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
    ListNode* reverse(ListNode* head){
        ListNode*p = NULL, *q = NULL, *r = head;

        while(r!= NULL){
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        head = q;
        return head;
    }
    int pairSum(ListNode* head) {
     ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=NULL){
            if(fast->next!=NULL){
                fast=fast->next->next;
            }
            else{
                fast=fast->next;
                continue;
            }
            prev=slow;
            slow=slow->next;}
        ListNode* second=reverse(slow);
        slow=second;
        ListNode* first=head;
        int ans=INT_MIN;
        while(second != NULL){
            int data = first->val + second->val;
            ans = max(ans,data);
            first = first->next;
            second = second->next;
        } 
    return ans ;  
    }
};