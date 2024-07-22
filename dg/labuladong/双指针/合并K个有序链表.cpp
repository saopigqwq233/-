#include "vector"
#include "queue"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//template<class T>
//class Greater{
//public:
//    bool operator()(T* x,T* y){
//        return x->val>y->val;
//    }
//};
template<>
class greater<ListNode*>{
public:
    bool operator()(ListNode*x,ListNode*y){
        return x->val>y->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,greater<ListNode*>>pq;
        ListNode*ret,*p;
        for(auto&head:lists){
            if(head!= nullptr)
                pq.push(head);
        }
        while (!pq.empty()){
            auto tmp = pq.top();
            if(!ret){
                ret = new ListNode(tmp->val);
                p = ret;
            }
            else{
                p->next = new ListNode(tmp->val);
                p = p->next;
            }
            pq.pop();
            if(tmp->next)
                pq.push(tmp->next);
        }
        return ret;
    }
};





