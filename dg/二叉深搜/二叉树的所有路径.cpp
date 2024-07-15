#include <cstring>
#include "string"
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
//此方法不可行，因为ret记录的不只是本条路上的路径，导致范围字符串加的时候会把本结点加到别的子树上
//class Solution {
//public:
//    void _binaryTreePaths(TreeNode* root,vector<string>&ret){
//        if(root== nullptr)//null_node
//            return ;
//        if(!root->left&&!root->right) {//leaves_node
//            ret.push_back(to_string(root->val));
//        }
//        _binaryTreePaths(root->left,ret);
//        _binaryTreePaths(root->right,ret);
//        for(auto&e:ret){
//            e = to_string(root->val)+"->"+e;
//        }
//    }
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string>ret;
//        _binaryTreePaths(root,ret);
//        return ret;
//    }
//};
class Solution {
public:

    //深度优先遍历
    //
    void _binaryTreePaths(TreeNode* root,string path,vector<string>&ret){
        if(!root)
            return;

        if(!root->left&&!root->right){
            path+= "->"+to_string(root->val);
            path.erase(path.begin(),path.begin()+2);
            ret.push_back(path);
            return;
        }
        _binaryTreePaths(root->left,path+"->"+to_string(root->val),ret);
        _binaryTreePaths(root->right,path+"->"+to_string(root->val),ret);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        //回溯恢复现场
        //p  dfs  数
        vector<string>ret;

        _binaryTreePaths(root, "",ret);
        return ret;
    }
};


















