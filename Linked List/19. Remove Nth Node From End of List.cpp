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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *current = head, *prev = head;

        int i = 0, k = 0, indx = 1;
        while (current != NULL)
        {
            k++;
            current = current->next;
        }

        i = k - n + 1;
        current = head;

        while (current != NULL)
        {
            if (indx == i)
            {
                if (current == head)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = current->next;
                }
                return head;
            }
            prev = current;
            indx++;
            current = current->next;
        }

        head = current;
        return head;
    }
};