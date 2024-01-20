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
        if(head==nullptr || head->next==nullptr) return nullptr;
        int cnt=0;
        int mid=size(head)/2;
        ListNode*prev=nullptr;
        ListNode*cur=head;
        while(cnt!=mid){
            if(cnt==0) prev=head;
            else prev=prev->next;
            cur=cur->next;
            cnt+=1;
        }
        prev->next=cur->next;
        return head;
    }
    int size(ListNode*head){
        int size=0;
        while(head){
            size+=1;
            head=head->next;
        }
        return size;
    }
};