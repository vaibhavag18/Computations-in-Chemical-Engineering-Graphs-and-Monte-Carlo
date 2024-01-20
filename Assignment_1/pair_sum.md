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

        //If size = 2
        if(head->next->next==NULL)
            return head->val+head->next->val;

        int max=INT_MIN,size=1,count=0;
        ListNode *low=head,*high=head,*mid;

        //calculating size of list
        while(high->next!=NULL)
        {
            high=high->next;
            size++;
        }
        cout<<size<<" ";
        //implementation of reverse list until size/2
        while(count<size/2)
        {
            low=low->next;
            count++;
        }
        mid=low->next;
        high=mid->next;

        while(high!=NULL)
        {
            mid->next=low;
            low=mid;
            mid=high;
            high=high->next;
        }
        mid->next=low;
        high=mid;
        mid=NULL;
        free(mid);  //deleting mid pointer

        //from here implementation of adding from start->right && end->left till size/2
        low=head;
        while(low->next!=high)
        {
            if(low->val+high->val>max)
                max=low->val+high->val;
            low=low->next;
            high=high->next;
            cout<<"*";
        }
        if(low->val+high->val > max)
            max=low->val+high->val;
        return max;
    }
};