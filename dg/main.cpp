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
            continue;
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
    cout<<endl;
}
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
    PrintDebug(l);
    Solution s;
    l = s.reverseKGroup(l,2);
    PrintDebug(l);
    return 0;
}