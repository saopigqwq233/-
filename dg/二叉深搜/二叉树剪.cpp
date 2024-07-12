//
// Created by Administrator on 24-7-12.
//
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
    TreeNode* _pruneTree(TreeNode* root){
        if(root== nullptr)
            return nullptr;
        if(root->left== nullptr&&root->right== nullptr)
            return root->val==0? nullptr:root;
        else{
            root->left = _pruneTree(root->left);
            root->right = _pruneTree(root->right);
            if(!root->left&&!root->right&&!root->val){
                return nullptr;
            }
            else
                return root;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        return _pruneTree(root);
    }
};





