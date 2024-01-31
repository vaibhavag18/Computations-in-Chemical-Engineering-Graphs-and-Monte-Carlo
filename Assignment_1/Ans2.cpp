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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*c = new ListNode(-5);
        ListNode*a = list1;
        ListNode*b = list2;
        ListNode*temp = c;

        while(a!=NULL && b!=NULL){
            if(b->val >= a->val){
                temp->next = a;
                temp = a;
                a = a->next;
            }
            else{
                temp->next = b;
                temp = b;
                b = b->next;
            }
        }

        if(a)
        temp->next = a;
        // a=a->next;
    
        else
        temp->next = b;
        // b=b->next;

        


        return c->next;



    }
};