//
// Created by Administrator on 24-7-11.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* _swapPairs(ListNode* head){
        if(head== nullptr)
            return nullptr;
        else if(head->next== nullptr)
            return head;
        else{
            ListNode* next = head->next;
            ListNode* nn = next->next;
            next->next = head;
            head->next = _swapPairs(nn);
            return next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        return _swapPairs(head);
    }
};





