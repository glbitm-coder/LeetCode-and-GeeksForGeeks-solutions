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
    int pairSum(ListNode* head) {
        
        ListNode* curr = head;
        int len = 0;
        
        while(curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        
        curr = head;
        ListNode* prev= NULL;
        int half = len / 2;
        
        while(half--)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = NULL;   
        prev = NULL;
        ListNode* n1 = head;
        
        while(curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode* n2 = prev;
        int ans = 0;
        while(n2 != NULL)
        {
            ans = max(ans, (n2->val) + (n1->val));
            n1 = n1->next;
            n2 = n2->next;
        }
        return ans;
    }
};