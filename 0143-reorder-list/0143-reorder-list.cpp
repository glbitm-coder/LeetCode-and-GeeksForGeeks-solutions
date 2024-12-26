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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, *prev = NULL, *temp = NULL;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast =  head, *temp1 = NULL, *temp2 = NULL;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverseList(slow->next);
        slow->next = NULL;
        slow = head;
        while(slow != NULL && fast != NULL){
            temp1 = slow->next;
            slow->next = fast;
            temp2 = fast->next;
            fast->next = temp1;
            slow = temp1;
            fast = temp2;
        }
        
        return ;
    }
};