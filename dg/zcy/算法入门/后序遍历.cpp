#include "iostream"
#include "vector"
#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//非递归版本
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return vector<int>();
        vector<int> ret;//返回值
        stack<TreeNode*>s;//保留现场
        s.push(root);
        TreeNode*h = root;//保留刚刚处理的结点
        TreeNode*cur= nullptr;//当前节点
        while (!cur||!s.empty()){
            cur = s.top();
            if(cur->left&&
            cur->left!=h&&
            cur->right!=h){//有左子树且左树没处理，开始处理左子树
                s.push(cur->left);
            }
            else if(cur->right
            &&cur->right!=h){//左树存在且已经没处理，开始处理右
                s.push(cur->right);
            }
            else{//左右均不存在或被处理
                ret.push_back(cur->val);
                h = cur;
                s.pop();
            }
        }
        return ret;
    }
};



