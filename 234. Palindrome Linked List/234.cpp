#include <iostream>
class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    bool isPalindrome(ListNode *head)
    {
        int a[999999];
        int counter = 0;

        ListNode *endOfList = head;
        ListNode *current = head;
        while (current != nullptr)
        {
            a[counter] = current->val;
            counter++;
            current = current->next;
        }
        bool equality = true;
        int j = counter - 1;
        for (int i = 0; i < counter / 2; i++)
        {
            while (j >= counter / 2)
            {
                if (a[i] != a[j])
                {
                    equality = false;
                }
                j--;
                break;
            }
        }
        return equality;
    }
    bool createListFromArr(int a[], int size)
    {
        ListNode *head = new ListNode();
        ListNode *current = head;
        current->val = a[0];
        for (int i = 1; i < size; i++)
        {
            current->next = new ListNode(a[i]);
            current = current->next;
        }
        return isPalindrome(head);
    }
};
int main()
{
    Solution *s = new Solution;
    int a[4] = {1, 2, 2, 1};
    std::cout << s->createListFromArr(a, sizeof(a) / sizeof(a[0]));
    return 0;
}