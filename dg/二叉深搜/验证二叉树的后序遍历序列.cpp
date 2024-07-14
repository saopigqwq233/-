//
// Created by Administrator on 24-7-13.
//
#include "vector"

using namespace std;

class Solution {
public:
    bool _verifyTreeOrder(vector<int>& postorder,int i,int j){
        if(i>=j)return true;//

        int small=i;//先遍历比根小的
        while (postorder[small]<postorder[j])small++;
        int bigger = small;
        while (postorder[bigger]>postorder[j])bigger++;
        return bigger==j
        &&_verifyTreeOrder(postorder,i,small-1)
        && _verifyTreeOrder(postorder,small,j-1);
    }
    bool verifyTreeOrder(vector<int>& postorder) {
        return _verifyTreeOrder(postorder,0,postorder.size()-1);
    }
};

