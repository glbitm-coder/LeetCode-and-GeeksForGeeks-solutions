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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head, *prev = NULL;
        int count = 1;
        while(count < left && curr != NULL){
            prev = curr;
            curr = curr->next;
            ++count;
        }
        if(prev == NULL){
            while(count <= right){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                ++count;
            }
            head->next = curr;
            head = prev;
        } else {
            ListNode *prev1 = prev;
            ListNode *curr1 = curr;
            while(count <= right){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                ++count;
            }
            prev1->next = prev;
            curr1->next = curr;

        }
        return head;
    }
};