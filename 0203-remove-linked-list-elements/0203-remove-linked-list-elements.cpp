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
    ListNode* removeElements(ListNode* head, int value) {
        ListNode* prev = NULL, *list = head;
        while(head != NULL && head->val == value)
        {
            head = head->next;
        }
        if(head == NULL)
        {
            return NULL;
        }
        else{
            prev = head;
            list = head;
            list = list->next;
        }
        
        while(list != NULL)
        {
            if(list->val == value)
            {
                prev->next = list->next;
            }
            else{
                prev = prev->next;
            }
            list = list->next;
            
        }
        return head;
    }
};