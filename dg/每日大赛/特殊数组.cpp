//
// Created by liu15 on 24-8-13.
//
#include "vector"

using namespace std;
#define dif(x,y) (((x)%2==0)&&((y)%2==1))||(((x)%2==1)&&((y)%2==0))
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ret = true;
        if(nums.size()==1)
            return ret;
        int i=0,j=1;
        while (j<nums.size()){
            if(!(dif(nums[i++],nums[j++]))) { ret = false;
                break;}
        }
        return ret;
    }
};