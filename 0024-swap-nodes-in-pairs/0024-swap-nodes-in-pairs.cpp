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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head, * tempHead = head;
        if(head == NULL || head->next == NULL) return head;
        if(head->next)
        {
            tempHead = tempHead->next;
        }
        ListNode* prev = head;
        while(curr && curr->next)
        {
            prev->next = curr->next;
            ListNode* temp = curr->next->next;
            curr->next->next = curr;
            curr->next = temp;
            
            prev = curr;
            curr = curr->next;
        }
        head = tempHead;
        return head;
        
    }
};