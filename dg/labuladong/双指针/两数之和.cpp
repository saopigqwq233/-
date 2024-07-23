#include "vector"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0,j = numbers.size();
        while (numbers[i]+numbers[j]!=target){
            int sum = numbers[i]+numbers[j];
            if(sum>target){
                --j;
            }
            else if(sum<target){
                ++i;
            }
            if(i==j||i>j)
                break;
        }
        return vector<int>{i+1,j+1};
    }
};