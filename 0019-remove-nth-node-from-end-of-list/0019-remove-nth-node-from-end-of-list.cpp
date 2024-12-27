/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int count(ListNode* head)
    {
        int c=0;
        ListNode* t=head;
        while(t!=NULL)
        {
            c++;
            t=t->next;
        
        }
        return c;
        
    }
class Solution {
public:
   ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* t=head,* s=head;  
       int p= count(head);
   if(p==1 && n==1)
   {t=NULL;
       head=NULL;
   }
        else
        {
        n=p-n;
        while(n--)
        {
            s=t;
            t=t->next;
        }
        s->next=t->next;
        t->next=NULL;
    //    free(t);
       }
        return head;
    }
};