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



//���������⣡��������
//û�и���endֵ��������



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

//����˼·

//1.void _reverse(ListNode*begin,ListNode*end)
//�ݹ�˼·������һ����㣬�ȷ�ת������Ľ�㣻
//�ú��������begin��end����Ľ�㣨��������������ת

//2.ListNode* _reverseKGroup(ListNode*prev,ListNode*begin,ListNode*end,ListNode*next)
//  1������begin��end��ת���begin�����end�ڿ�ͷ����prev�ǲ��ǿգ��ǲ��ǵ�һ�飩
//�ú��������prev  ��   next����Ľ�㷴ת�����������Ǳ��������������䣬
// ������һ���ǰһ����㣬��begin
// ����Ҫ�������������prevΪnull

//3.���ĺ���ListNode* reverseKGroup(ListNode* head, int k)
//�����k��һ��   ���飬ÿ���в�ͬ�����
//�ֱ�Բ�ͬ��������з�ת

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