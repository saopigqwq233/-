//
// Created by Administrator on 24-9-13.
//
#include "Comm.h"
class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
        for(auto e:nums1){
            auto index = std::find(nums2.begin(), nums2.end(),e);
            auto max_index = index;
            while (max_index!=nums2.end()){
                if(*max_index>e){
                    ret.push_back(*max_index);
                    break;
                }
                ++max_index;
            }
            if(max_index==nums2.end())
                ret.push_back(-1);
        }
        return ret;
    }
};
//int main(){
//    Solution s;
//    vector<int>n1{4,1,2},n2{1,2,3,4};
//    s.nextGreaterElement(n1,n2);
//    return 0;
//}