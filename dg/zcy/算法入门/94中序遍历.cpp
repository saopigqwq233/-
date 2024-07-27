#include "vector"
#include "stack"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return vector<int>();
        vector<int> ret;
        stack<TreeNode*> s;
        while (!s.empty()||root){
            while (root){
                s.push(root);;
                root = root->left;
            }
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};



