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
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head, ans;

        int n = 0, i = 0;
        while(current!=NULL)
        {
            n++;
            current = current->next;
        }
        n = n/2;
        current = head;
        
        while(current!=NULL)
        {
            if( i == n)
                return current;
            else
                i++;
            
            current = current->next;
        }

        return current;
    }
};