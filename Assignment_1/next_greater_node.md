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
        stack<int> st;
        ListNode* curr = head;
        vector<int> arr;
        int x = 0;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
            x++;
        }

        vector<int> ans;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            ans.push_back(st.empty() ? 0 : st.top());
            st.push(arr[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};