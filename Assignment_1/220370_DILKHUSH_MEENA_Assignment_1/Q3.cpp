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
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size()-1;
        //int max=v[n];
     //v[n]=0;
        for(int i=0;i<=n-1;i++)
        {
            int x=v[i];
            for(int j=i+1;j<=n;j++)
            {
            if(v[j]>x)
            {
                v[i]=v[j];
                break;
            }   
            }
            if(v[i]==x)
                v[i]=0
        }
        v[n]=0;
        return v;
    }
};