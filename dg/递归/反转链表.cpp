
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
        if(cur->next == nullptr) {//最后一个结点
            cur->next = pre;
            return cur;
        }
        else{//每到一个结点，先把后面的结点反转
            ListNode*ret = _reverseList(cur,cur->next,cur->next->next);
            if(pre)//前面一个结点存在，防止只有一个结点的情况
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