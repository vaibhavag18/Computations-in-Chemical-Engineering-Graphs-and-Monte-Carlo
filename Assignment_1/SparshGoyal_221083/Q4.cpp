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
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        int size = v.size();
        int max_ = -1;
        for (int i =0 ; i<=(size/2)-1;i++){
            max_ = max(max_,v[i]+v[size-1-i]);
        }
        return max_;

    }
};