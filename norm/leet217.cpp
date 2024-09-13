//
// Created by Administrator on 24-9-13.
//
#include "Comm.h"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto &e:nums){
            int n = ++map[e];
            if(n==2)
                return true;
        }
        return false;
    }
};