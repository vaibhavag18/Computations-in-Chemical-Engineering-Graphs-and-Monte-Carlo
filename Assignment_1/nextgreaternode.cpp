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
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        stack<int> st;
        for(int i = 0 ; i < arr.size() ; i++ ){
            if(st.empty()||(!st.empty()&&arr[i]<=arr[st.top()]) ){
                st.push(i);}
            else{ // means ( arr[i] > arr[st.top()] ) 
            while(!st.empty() && ( arr[i] > arr[st.top()] ) ){
                arr[st.top()] = arr[i];
                st.pop();}
            st.push(i);}
        }
        while(!st.empty()){
            arr[st.top()] = 0;
            st.pop();}
       return arr; 
    }
};