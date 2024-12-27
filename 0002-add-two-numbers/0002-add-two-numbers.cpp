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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1, *head2 = l2, *prev = NULL;
        int carry = 0, curr = 0;
        while(l1 != NULL && l2 != NULL){
            prev = l1;
            curr = l1->val + l2->val + carry;
            l1->val = curr % 10;
            l2->val = curr % 10;
            l1 = l1->next;
            l2 = l2->next;
            carry = curr / 10;
        }
        if(l1 != NULL){
            while(l1 != NULL){
                prev = l1;
                curr = l1->val + carry;
                l1->val = curr % 10;
                carry = curr / 10;
                l1 = l1->next;
            }
            if(carry == 1){
                prev->next = new ListNode(1);
            }
            return head1;
        }
        if(l2 != NULL){
            while(l2 != NULL){
                prev = l2;
                curr = l2->val + carry;
                l2->val = curr % 10;
                carry = curr / 10;
                l2 = l2->next;
            }
            if(carry == 1){
                prev->next = new ListNode(1);
            }
            return head2;
        }
        if(carry == 1){
            prev->next = new ListNode(1);
        }
        return head1;
    }
};