#include "Comm.h"
class Solution {
public:
    int count = 0;
    int deepth(TreeNode*root){
        if(!root)
            return 0;
        int l = deepth(root->left),r = deepth(root->right);
        return 1+(l>r?l:r);
    }
    int diameterOfBinaryTree(TreeNode *root) {
        if(!root)
            return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        int temp = deepth(root->left) + deepth(root->right);
        if(temp>count)
            count = temp;
        return count;
    }
};