#include "unordered_map"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//双指针法
//A链长a，B链长b，分别在各自的第i、j个节点相交
//后续节点相同，可以得到a-i = b-j --->a+j == b+i
//这不就是pb遍历完B去遍历A,pa遍历完A遍历B，最后遇到的地方就是相交点

//如果没相交，就是各自遍历复杂度为2N

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool ca = false,cb = false;
        if(headA==headB)
            return headA;
        ListNode*pa = headA,*pb = headB;
        while (pa!=pb){
            if(pa) pa = pa->next;
            else {
                if(!ca) { pa = headB; ca = true;}
                else
                    return nullptr;
            }

            if(pb) pb = pb->next;
            else{
                if(!cb){pb = headA;cb = true;}
                else
                    return nullptr;
            }
        }
        return pa;
    }
};




//hash表法，太rz了
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        unordered_map<ListNode*,int>r;
//        ListNode*pa = headA,*pb = headB;
//        while (pa){
//            r[pa]+=1;
//            pa = pa->next;
//        }
//        while (pb){
//            r[pb]+=1;
//            if(r[pb]==2){
//                return pb;
//            }
//            pb = pb->next;
//        }
//        return nullptr;
//    }
//};