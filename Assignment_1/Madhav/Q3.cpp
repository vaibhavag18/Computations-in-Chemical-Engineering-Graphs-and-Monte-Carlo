#include <iostream>
#include <vector>
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    std::vector<int> nextLargerNodes(ListNode *head)
    {
        std::vector<int> LLarr;
        while (head != NULL)
        {
            LLarr.push_back(head->val);
            head = head->next;
        }
        int cnt = LLarr.size();
        std::stack<int> st;
        st.push(0);
        for (int i = cnt - 1; i >= 0; i--)
        {
            int curr = LLarr[i];
            while (!st.empty() && curr >= st.top())
            {
                st.pop();
            }
            LLarr[i] = st.empty() ? 0 : st.top();
            st.push(curr);
        }
        return LLarr;
    }
};

void printVector(const std::vector<int> &vec)
{
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{

    ListNode *head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    std::vector<int> result = solution.nextLargerNodes(head);

    std::cout << "Result Vector: ";
    printVector(result);

    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
