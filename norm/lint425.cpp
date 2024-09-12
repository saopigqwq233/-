#include "Comm.h"


class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        ListNode*p = head,*prev = head;
        while (p){
            if(p->val==val){
                if(p!=head){
                    prev->next = p->next;
                    delete p;
                    p = prev->next;
                }
                else{
                    head = head->next;
                    p = prev = head;
                }
            }
            else {
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};