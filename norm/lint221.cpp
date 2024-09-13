//
// Created by Administrator on 24-9-13.
//
#include "Comm.h"
class Solution {
public:
    ListNode* addlists(stack<int>&s1,stack<int>&s2){
        ListNode* ret= nullptr;
        int c=0;
        int sum;
        while (!s1.empty()&&!s2.empty()){
            sum = s1.top()+s2.top()+c;
            c = sum/10;
            s1.pop(),s2.pop();
            if(ret == nullptr){
                ret = new ListNode(sum%10);
                continue;
            }
            auto new_node = new ListNode(sum%10);
            new_node->next = ret;
            ret = new_node;
        }
        if(!s1.empty()){
            while (!s1.empty()){
                sum = c+s1.top();
                c = sum/10;
                s1.pop();
                auto new_node = new ListNode(sum%10);
                new_node->next = ret;
                ret = new_node;
            }
        }
        if(!s2.empty()){
            while (!s2.empty()){
                sum = c+s2.top();
                c = sum/10;
                s2.pop();
                auto new_node = new ListNode(sum%10);
                new_node->next = ret;
                ret = new_node;
            }
        }
        if(c==1){
            auto new_node = new ListNode(1);
            new_node->next = ret;
            ret = new_node;
        }
        return ret;
    }
    ListNode* addLists2(ListNode *l1, ListNode *l2) {
        stack<int>s1,s2;
        auto p1 = l1,p2 = l2;
        while (p1){
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2){
            s2.push(p2->val);
            p2 = p2->next;
        }
        return addlists(s1,s2);
    }
};