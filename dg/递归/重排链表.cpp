#include "algorithm"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//大致意思是
// 把 0 1 2 3 4 5 6....n   重排序
//    0 n 1 n-1 2 n-2...
//可以想象到其实是把后半链表倒转，然后和前半链表合并
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
    void _merge(ListNode*l1,ListNode*l2){
        ListNode*p1 = l1,*p2 = l2;
        while (!p1&&!p2){
            ListNode*p1tmp = p1->next;
            ListNode*p2tmp = p2->next;

            p1->next = p2;
            p2->next = p1tmp;

            p1 = p1tmp;
            p2 = p2tmp;
        }
    }
    ListNode*_mid(ListNode*head){
        ListNode*mid = head,*end = head;
        while (end&&end->next){
            end = end->next;
            if(end->next)
                end = end->next;
            else{
                return mid;
            }
            mid = mid->next;
        }
        return mid;
    }
    void reorderList(ListNode* head) {
        if(head== nullptr)
            return;
        //双指针定到中间和结尾
        ListNode*mid = _mid(head);
        ListNode* l2 = reverseList(mid->next);
        mid->next = nullptr;
        _merge(head,l2);
    }
};















