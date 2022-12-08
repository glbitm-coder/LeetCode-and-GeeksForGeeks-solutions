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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
        {
            return head;
        } 
        ListNode* odd = head, * even = head->next, *even_start = head->next;
        while(true)
        {
            if(even->next)
            {
                odd->next = even->next;
                odd = odd->next;
            }
            else{
                break;
            }
            if(odd->next)
            {
                even->next = odd->next;
                even = even->next;
            }
            else{
                break;
            }

        }
        even->next = NULL;
        odd->next = even_start;
        return head;
    }
};