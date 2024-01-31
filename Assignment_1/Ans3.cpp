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
        vector<int> ans;
        stack<int> sta;
    while(head!=NULL)
    {
        ans.push_back(head->val);
        head = head->next;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int a = ans[i];

        while (!sta.empty() && sta.top() <= ans[i]){
            sta.pop();
        }
//         if (sta.empty()) {
//           ans[i] = 0;
//         } 
//         else {
//           ans[i] = sta.top();
// }

        ans[i] = sta.empty() ? 0 : sta.top();
        sta.push(a);
    }
    return ans;

            
        }

       
        
    
};