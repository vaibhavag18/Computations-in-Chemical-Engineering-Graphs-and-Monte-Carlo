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
        vector<int> v;
        int maxSum = 0;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        for(int i=0; i<v.size()/2; i++){
            maxSum = max((v[i]+v[v.size()-i-1]), maxSum);
        }
        return maxSum;
    }
};