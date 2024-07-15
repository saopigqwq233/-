
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//递归版本
//class Solution {
//public:
//    void _addTwoNumbers(ListNode*& l,ListNode* l1, ListNode* l2,int c){
//        if(!l1&&!l2){//l1  l2 遍历结束
//            if(c){//还有进位
//                auto NN = new ListNode(1);
//                l = NN;
//            }
//            return;
//        }
//        if(!l1){
//            int sum = l2->val+c;
//            auto NN = new ListNode(sum%10);
//            l = NN;
//            _addTwoNumbers(NN->next, nullptr,l2->next,sum>9?1:0);
//            return;
//        }
//        if(!l2){
//            int sum = l1->val+c;
//            auto NN = new ListNode(sum%10);
//            l = NN;
//            _addTwoNumbers(NN->next, l1->next, nullptr,sum>9?1:0);
//            return;
//        }
//        int sum = l1->val+l2->val+c;
//        auto NN = new ListNode(sum%10);
//        l = NN;
//        _addTwoNumbers(NN->next,l1->next,l2->next,sum>9?1:0);
//    }
//
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        int sum = l1->val+l2->val;
//        ListNode* ret = new ListNode(sum%10);
//        _addTwoNumbers(ret->next,l1->next,l2->next,sum>9?1:0);
//        return ret;
//    }
//};

//非递归版本
class Solution {
public:
    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2){
       //双指针
        ListNode* p1 = l1,*p2 = l2;
        ListNode*ret;
        int out = p1->val+p2->val;
        ret = new ListNode(out%10);
        ListNode*p = ret;
        int c = out>9?1:0;
        p1 = p1->next;
        p2 = p2->next;
        while (p1&&p2){
            int sum = p1->val+p2->val+c;
            ListNode* NN = new ListNode(sum%10);
            p->next = NN;

            p = p->next;
            c = sum>9?1:0;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1){
            int sum = p1->val+c;
            ListNode*NN = new ListNode(sum%10);
            p->next = NN;
            p = p->next;

            c = sum>9?1:0;
            p1 = p1->next;
        }
        while (p2){
            int sum = p2->val+c;
            ListNode* NN = new ListNode(sum%10);
            p->next = NN;
            p = p->next;

            c = sum>9?1:0;
            p2 = p2->next;
        }
        if(c)
            p->next = new ListNode(1);

        return ret;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return _addTwoNumbers(l1,l2);
    }
};









