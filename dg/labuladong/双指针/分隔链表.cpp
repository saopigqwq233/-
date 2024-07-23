struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //双指针left，right遍历链表，left定到第一个大于x的结点，然后把right遇到的小于x的结点取出来插到left前
        if(!head||!head->next)
            return head;

        ListNode* ret = head;
        ListNode*left = head,*right;
        ListNode*prev_left = nullptr;//在left定位时、插入小于x节点时更新
        while (left&&left->val<x){
            prev_left = left;
            left = left->next;
        }

        if(!left)//没有比x大或等的
            return ret;
        //left定到第一个大于x的结点
        right = left->next;
        ListNode* prev_right = left;
        while (right){
            if(right->val<x){//遇到比x小的结点
                if(prev_left== nullptr){//left定到了head上
                    prev_right->next = right->next;
                    right->next = head;
                    ret = right;
                    prev_left = right;
                }
                else{
                    prev_right->next = right->next;
                    right->next = prev_left->next;
                    prev_left->next = right;
                    prev_left = prev_left->next;
                }
                right = prev_right->next;
            }
            else{
                prev_right = right;
                right = right->next;
            }
        }
        return ret;
    }
};


//搞错了，不是快排的那个意思，看题！！！！
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if(head== nullptr)
//            return nullptr;
//        ListNode* smaller = nullptr,*ps = nullptr;
//        ListNode* greater = nullptr,*pg = nullptr;
//        ListNode* target = nullptr;
//        ListNode* p = head;
//        while (p){
//            auto tmp = p;
//            p = p->next;
//            //遇到比x小的
//            if(tmp->val<x){
//                if(smaller){//先判断smaller是不是空
//                    ps->next = tmp;
//                    ps = ps->next;
//                }
//                else{
//                    smaller = tmp;
//                    ps = smaller;
//                }
//                ps->next = nullptr;
//            }
//            else if(tmp->val>x){
//                if(greater){
//                    pg->next = tmp;
//                    pg = pg->next;
//                }
//                else{
//                    greater = tmp;
//                    pg = greater;
//                }
//                pg->next = nullptr;
//            }
//            else
//                target = tmp;
//        }
//        if(target){
//            ps->next = target;
//            target->next = greater;
//        }
//        else{
//            ps->next = greater;
//        }
//        return smaller;
//    }
//};




