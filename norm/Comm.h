//
// Created by Administrator on 24-9-11.
//

#ifndef HOMEWORK1_COMM_H
#define HOMEWORK1_COMM_H
#include "vector"
#include "string"
#include "map"
#include "unordered_map"
#include "set"
#include "algorithm"
#include "queue"
#include "stack"
#include "list"
#include "iostream"
using namespace std;




class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}



#endif //HOMEWORK1_COMM_H
