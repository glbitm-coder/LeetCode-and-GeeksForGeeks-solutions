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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        if(k == 1){
            return head;
        }

        int count = 0;
        ListNode* curr = head;
        ListNode* prev = curr, *temp = NULL, *groupStart = head, *nextGroupStart = NULL, *temp_curr = NULL;
        curr = curr->next;
        ++count;

        while(count < k){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            ++count;
        }
        
        head = prev;
        
        while(curr != NULL){
            count = 1;
            prev = curr;
            nextGroupStart = prev;

            int c1 = 0;
            temp_curr = curr;
            while(temp_curr != NULL){
                temp_curr = temp_curr->next;
                ++c1;
            }
            if(c1 < k){
                groupStart->next = nextGroupStart;
                return head;
            }
            
            curr = curr->next;
            
            while(count != k && curr != NULL){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                ++count;
            }
            groupStart->next = prev;
            groupStart = nextGroupStart;



        }
        groupStart->next = NULL;
        return head;
    }
};