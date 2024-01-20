// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverse(ListNode* &head){
//         if(head==NULL || head->next==NULL)return head;

//         ListNode* prev=NULL;
//         ListNode* curr=head;

//         while(curr){
//             ListNode* nex=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=nex;
//         }
//         return prev;
//     }

//     int pairSum(ListNode* head) {
//         ListNode* slow=head;
//         ListNode* fast=head;
//         ListNode* prev=NULL;

//         while(fast && fast->next){
//             prev=slow;
//             slow=slow->next;
//             fast=fast->next->next;
//         }

//         prev->next=NULL;
//         slow=reverse(slow);
//         fast=head;

//         int mx=0;
//         while(slow){
//             mx=max(mx,slow->val+fast->val);
//             slow=slow->next;
//             fast=fast->next;
//         }

//         return mx;
//     }
// };

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
    ListNode* reverse(ListNode* &head){
        if(head==NULL || head->next==NULL)return head;

        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reverse(slow->next);
        slow=slow->next;
        fast=head;

        int mx=0;
        while(slow){
            mx=max(mx,slow->val+fast->val);
            slow=slow->next;
            fast=fast->next;
        }

        return mx;
    }
};