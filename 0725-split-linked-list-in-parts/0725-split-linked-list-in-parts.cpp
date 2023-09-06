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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr = head;
        int count = 0;
        while(curr != NULL){
            ++count;
            curr = curr->next;
        }
        int mini = count / k;
        int extras = count <= k ? 0 : count % k;
        curr = head;
        vector<ListNode*> ans;
        ListNode* temp = head;
        int j = 0;
        while(k--){
            curr = temp;
            if(curr != NULL){
                ans.push_back(curr);
            }else{
                ans.push_back(curr);
                continue;
            }
            int i = 1;
            while(i < mini && curr != NULL){
                curr = curr->next;
                ++i;
            }
            if(j < extras){
                curr = curr->next;
                ++j;
            }
            temp = curr->next;
            curr->next = NULL;
        }
        return ans;
    }
};