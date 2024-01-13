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
        vector<int> v;
        stack<int> s;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int> ans(v.size(),0);
        for(int i=0; i<ans.size(); i++){
            while(!s.empty() && v[i]>v[s.top()]){
                ans[s.top()]=v[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};