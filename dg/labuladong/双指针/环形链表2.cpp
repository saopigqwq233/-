
#include "unordered_map"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//哈希表方式
//每访问到一个结点，就对该结点的映射值+1，
// 随后只需要检查当前结点是否是2就可找到第一个
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>r;
        ListNode*p = head;
        while (p){
            r[p] += 1;
            if(r[p]==2)
                return p;
            p = p->next;
        }
        return nullptr;
    }
};




//双指针法
//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head) {
//        if(!head||!head->next)
//            return nullptr;
//        ListNode*slow = head,*fast = head;
//        ListNode* p = nullptr;
//
//        while (fast&&slow){
//            slow = slow->next;
//            fast = fast->next;
//            if(fast)
//                fast = fast->next;
//            else{
//                break;
//            }
//            if(fast==slow){
//                p = fast;
//                break;
//            }
//        }
//        if(!p) return nullptr;
//        slow = head;
//        while (slow != p){
//            slow = slow->next;
//            p = p->next;
//        }
//        return p;
//    }
//};





