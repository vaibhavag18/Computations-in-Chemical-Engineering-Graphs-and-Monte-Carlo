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
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        ListNode* temp2=head;
        if(head==NULL || head->next==NULL) return NULL;
        for(int i=0; i<=cnt/2; i++){
            if(i==cnt/2-1){
                ListNode* deleteNode = temp2->next;
                temp2->next=temp2->next->next;
                delete deleteNode;
            }
            if(temp2->next!=NULL) temp2=temp2->next;
        }
        return head;
    }
};