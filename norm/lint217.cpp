#include "Comm.h"
class Solution {
public:
    ListNode* removeDuplicates(ListNode*head) {
        map<int,bool> map;
        auto p = head,prev = head;
        while (p!= nullptr){
            if(map[p->val]){
                prev->next = p->next;
                delete p;
                p = prev->next;
            }
            else{
                map[p->val]= true;
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};
//int main(){
//    cout<<bool()<<endl;
//}