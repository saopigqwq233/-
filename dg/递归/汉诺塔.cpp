//
// Created by Administrator on 24-7-9.
//
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    void move(int n,vector<int>& src,vector<int>& tmp,vector<int>& dest){
        if(n==1){
            dest.push_back(src.back());
            src.pop_back();
            return;
        }

        move(n-1,src,dest,tmp);
        dest.push_back(src.back());
        src.pop_back();
        move(n-1,tmp,src,dest);
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(), A, B, C);
    }
};