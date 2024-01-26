#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        int cnt = 0;
        int mid = size(head) / 2;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cnt != mid)
        {
            if (cnt == 0)
                prev = head;
            else
                prev = prev->next;
            cur = cur->next;
            cnt += 1;
        }
        prev->next = cur->next;
        return head;
    }

    int size(ListNode *head)
    {
        int size = 0;
        while (head)
        {
            size += 1;
            head = head->next;
        }
        return size;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    ListNode *modifiedList = solution.deleteMiddle(head);

    std::cout << "Modified Linked List: ";
    printList(modifiedList);

    while (modifiedList)
    {
        ListNode *temp = modifiedList;
        modifiedList = modifiedList->next;
        delete temp;
    }

    return 0;
}
