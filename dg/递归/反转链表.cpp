
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* _reverseList(ListNode* pre,ListNode*cur,ListNode*next){
        if(cur->next == nullptr) {
            if(pre)
                pre->next= nullptr;
            cur->next = pre;
            return cur;
        }
        else{
            ListNode*ret = _reverseList(cur,cur->next,cur->next->next);
            if(pre)
                pre->next= nullptr;
            cur->next = pre;
            return ret;
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head== nullptr)
            return nullptr;
        return _reverseList(nullptr,head,head->next);
    }
};