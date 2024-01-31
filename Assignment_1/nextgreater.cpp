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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> initial;
        stack<int> st;
        while(head!=NULL){
            initial.push_back(head->val);
            head=head->next;
        }
        vector<int> result(initial.size(),0);
        for(int i=0;i<initial.size();i++){
            while(!st.empty() and initial[st.top()]<initial[i]){
                result[st.top()]=initial[i];
                st.pop();
            }
            st.push(i);
        }
    return result;
    }
};
