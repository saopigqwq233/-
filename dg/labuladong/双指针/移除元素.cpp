#include "vector"
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0;
        //i是元素放入的位子，j遍历找不是val的
        int size = nums.size();
        while (j<size){
            if(nums[j]!=val){
                nums[i] = nums[j];
                ++i;
            }
            ++j;
        }
        return i;
    }
};