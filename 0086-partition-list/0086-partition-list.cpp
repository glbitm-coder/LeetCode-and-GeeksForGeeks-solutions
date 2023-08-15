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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode* h1 = new ListNode();
    h1->val = INT_MAX;
    h1->next = head;
    ListNode* h2 = new ListNode();
    h2->val = INT_MIN;
    h2->next = head;
    ListNode* curr = head;
    ListNode* prev = h1;
    ListNode* curr2 = h2;
    while(curr != NULL)
    {
        if(curr->val < x)
        {
            prev->next = curr;
            prev = prev->next;
            
        }
        else{
            curr2->next = curr;
            curr2 = curr2->next;
            
        }
        curr = curr->next;
    }
            curr2->next = NULL; 
    ListNode* temp = h2->next;
    prev->next = temp;
    return h1->next;
    }
};