//
// Created by liu15 on 24-8-15.
//
#include "algorithm"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int min_in_two(int a,int b){
        return a>b?b:a;
    }
    int min_in_four(int a,int b,int c,int d){
        int min_x = a>b?b:a;
        int min_y = c>d?d:c;
        return min_x>min_y?min_y:min_x;
    }
    int left_right(TreeNode*root){
        TreeNode*p = root->left;
        while (p){
            if(p->right){
                p = p->right;
            }
            else
                return p->val;
        }
        return p->val;
    }
    int right_left(TreeNode*root){
        TreeNode*p = root->right;
        while (p){
            if(p->left){
                p = p->left;
            }
            else
                return p->val;
        }
        return p->val;
    }
    int getMinimumDifference(TreeNode* root) {
        if(root->left&&root->right){//正常情况，只需要比较左子树、右子树和本节点与左子树最右节点，右子树最左节点的差值
            return min_in_four(
                    abs(root->val- left_right(root)),
                    abs(root->val- right_left(root)),
                    getMinimumDifference(root->left),
                    getMinimumDifference(root->right));
        }
        else if(root->left&&!root->right){//左子树在右子树不在
            return min_in_two(abs(root->val- left_right(root)),
                              getMinimumDifference(root->left));
        }
        else if(!root->left&&root->right){
            return min_in_two(abs(root->val- right_left(root)),
                              getMinimumDifference(root->right));
        }
        else
            return 100000;
    }
};




