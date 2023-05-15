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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        ListNode* p1 = head, *p2 = head, *prev1 = NULL, *prev2 = NULL;
        
        if(head == NULL) return head;
        
        while(curr != NULL)
        {
            curr = curr->next;
            len++;
        }
        
        if(k > len) return head;
        
        
        int k1 = k - 1, k2 = len - k;
        
        
        while(k1--)
        {
            prev1= p1;
            p1 = p1->next;
        }
        while(k2--)
        {
            prev2 = p2;
            p2 = p2->next;
        }
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
        return head;
        
    }
};