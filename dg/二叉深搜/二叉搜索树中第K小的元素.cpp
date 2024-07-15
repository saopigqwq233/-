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
//class Solution {
//public:
//    int kthSmallest(TreeNode* root, int k) {
//        stack<TreeNode* > s;
//        s.push(root);
//        root = root->left;
//        while (root&&!s.empty()){
//            while (root){
//                s.push(root);
//                root = root->left;
//            }
//            root = s.top();
//            s.pop();
//            --k;
//            if(k==0){
//                return root->val;
//            }
//            root = root->right;
//        }
//        return root->val;
//    }
//};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode* > s;
        s.push(root);
        root = root->left;
        //为什么是或，并且是这两个条件
        //1.针对每一个结点，需要遍历左子树、父亲、右子树
        //2.栈内保存左子树还不为空的结点等待出栈
        //3.出栈时，说明左子树结束，到父亲了
        //4.root此时再移动到右子树上

        //栈内还有元素，说明有没访问的结点，需要出栈
        //root还不为空，说明需要中序遍历以此节点为父亲的树

        //所以，当栈和root皆为空时，才停止遍历
        while (root||!s.empty()){
            while (root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            --k;
            if(k==0){
                return root->val;
            }
            root = root->right;
        }
        return root->val;
    }
};