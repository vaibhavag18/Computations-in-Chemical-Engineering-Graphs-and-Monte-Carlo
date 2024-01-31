class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        // let's first reverse the linked list , other choice is to store in a vector
        ListNode* prev_ptr = NULL;
        ListNode* curr_ptr = head;
        int size = 0;
        while(curr_ptr){
            ListNode* next_ptr = curr_ptr->next;
            curr_ptr->next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
            size++;
        }
        // now pre_ptr will be pointing to head of reversed linked list;
        // now let's find next greater element for each node;
        vector<int> ans(size,0);
        int i = size-1;
        ListNode* temp = prev_ptr;
        while(temp){
            while(!st.empty() and st.top()<=temp->val) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(temp->val);
            i--;
            temp = temp->next;
        }
        return ans;
    }
};