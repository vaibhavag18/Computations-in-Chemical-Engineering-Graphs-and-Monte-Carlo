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
    int pairSum(ListNode* head) {
        if(head==NULL) return 0;

        if(head->next->next==NULL) return head->val + head->next->val;
        stack<int>st;
        stack<int>st1;
        stack<int>st2;

        while(head){
            st.push(head->val);
            st1.push(head->val);
            head=head->next;
        }

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        int x=0;
        while(!st.empty() && !st2.empty()){
            x=max(x,st.top()+st2.top());
            st.pop();
            st2.pop();
        }

        return x;

    }
};
