#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* create(int a[],int n){
    ListNode*ret;
    ListNode*p;
    for(int i=0;i<n;i++){
        if(!ret){
            ret = new ListNode(a[i]);
            p = ret;
        }
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    return ret;
}
void PrintDebug(ListNode*l){
    while (l){
        cout<<l->val<<' ';
        l = l->next;
    }
}



//大函数有问题！！！！！
//没有更新end值！！！！



//class Solution {
//public:
//    void _reverse(ListNode*begin,ListNode*end){
//        if(begin==end)
//            return;
//        if(begin->next==end) {
//            end->next = begin;
//            return;
//        }
//        ListNode*next = begin->next;
//        _reverse(begin->next,end);
//        next->next = begin;
//    }
//
//    ListNode* _reverseKGroup(ListNode*prev,ListNode*begin,ListNode*end,ListNode*next){
//        _reverse(begin,end);
//        begin->next = next;
//        if(prev)
//            prev->next = end;
//
//        return begin;
//    }
//
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        int cnt = 0;
//        ListNode*begin = head;
//        ListNode*end = head;
//        ListNode*ret;
//        for(;end;end=end->next){
//            ++cnt;
//            if(cnt%k==0){
//                begin = _reverseKGroup(nullptr,begin,end,end->next);
//                ret = end;
//                end = end->next;
//                break;
//            }
//        }
//        for(;end;end=end->next){
//            ++cnt;
//            if(cnt%k==0){
//                begin = _reverseKGroup(begin,begin->next,end,end->next);
//            }
//        }
//        return ret;
//    }
//};

//大致思路

//1.void _reverse(ListNode*begin,ListNode*end)
//递归思路：遇到一个结点，先反转他后面的结点；
//该函数负责把begin到end区间的结点（包含他们自身）反转

//2.ListNode* _reverseKGroup(ListNode*prev,ListNode*begin,ListNode*end,ListNode*next)
//  1函数把begin到end反转完后，begin在最后，end在开头，看prev是不是空（是不是第一组）
//该函数负责把prev  到   next区间的结点反转（不包含他们本身），并连接区间，
// 返回下一组的前一个结点，即begin
// 但需要处理特殊情况入prev为null

//3.最大的函数ListNode* reverseKGroup(ListNode* head, int k)
//负责对k个一组   分组，每组有不同的情况
//分别对不同的情况进行翻转

class Solution {
public:
    void _reverse(ListNode*begin,ListNode*end){
        if(begin==end)
            return;
        if(begin->next==end) {
            end->next = begin;
            return;
        }
        ListNode*next = begin->next;
        _reverse(begin->next,end);
        next->next = begin;
    }

    ListNode* _reverseKGroup(ListNode*prev,ListNode*begin,ListNode*end,ListNode*next){
        _reverse(begin,end);
        begin->next = next;
        if(prev)
            prev->next = end;

        return begin;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode*begin = head;
        ListNode*end = head;
        ListNode*ret;
        for(;end;end=end->next){
            ++cnt;
            if(cnt%k==0){
                begin = _reverseKGroup(nullptr,begin,end,end->next);
                ret = end;
                end = begin->next;
                break;
            }
        }
        for(;end;){
            ++cnt;
            if(cnt%k==0){
                begin = _reverseKGroup(begin,begin->next,end,end->next);
                end = begin->next;
            }
            else
                end = end->next;
        }
        return ret;
    }
};
int main(){
    int a[5]={1,2,3,4,5};
    ListNode *l = create(a,5);
    Solution s;
    l = s.reverseKGroup(l,2);
    PrintDebug(l);
    return 0;
}