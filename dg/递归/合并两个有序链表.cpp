struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//双指针法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    }
};




//递归法
// 遇到两个链表，如果哪个为空，就返回另一个
//都不为空，则取小结点数据到作为返回节点，小数据结点后面接后续的merg结果
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if(list1== nullptr)
//            return list2;
//        else if(list2== nullptr)
//            return list1;
//
//        ListNode* ret;
//        if(list1->val<list2->val){
//            ret = list1;
//            ret->next = mergeTwoLists(list1->next,list2);
//        }
//        else
//        {
//            ret = list2;
//            ret->next = mergeTwoLists(list1,list2->next);
//        }
//        return ret;
//    }
//};