//
// Created by Administrator on 24-9-11.
//
#include "Comm.h"
static int i = 1;
class Solution {
public:
    vector<int> kClosestNumbers(vector<int> &a, int target, int k) {
        int index = 0;
        while (index!=a.size()){
            if(a[index]==target||a[index]>target){
                if(index==0){
                    return {a.begin(),a.begin()+k};
                }
                else if(index==a.size()-1){
                    return {a.rbegin(),a.rbegin()+k};
                }
                else
                    break;
            }
            else
                ++index;
        }
        vector<int> ret;
        int left = index-1,right = index;
        while (left>-1&&right<a.size()&&k){
            int left_abs = abs(a[left]-target),right_abs = abs(a[right]-target);
            if(left_abs<right_abs){
                ret.push_back(a[left]);
                --left;
            }
            else if(left_abs>right_abs){
                ret.push_back(a[right]);
                ++right;
            }
            else{
                if(a[left]<a[right]){
                    ret.push_back(a[left]);
                    --left;
                }
                else if(a[left]>a[right]){
                    ret.push_back(a[right]);
                    ++right;
                }
            }
            --k;
        }
        while (left>-1&&k){
            ret.push_back(a[left]);
            --left;
            --k;
        }
        while(right<a.size()&&k){
            ret.push_back(a[right]);
            ++right;
            --k;
        }
        return ret;
    }
};
//int main(){
//    Solution s;
//    vector<int> v{1,2,3};
//    auto ret = s.kClosestNumbers(v,2,3);
//    for(auto e:ret){
//        cout<<e<<' ';
//    }
//    return 0;
//}