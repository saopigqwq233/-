#include "vector"

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int l = 0,r = nums.size()-1;
        int ans = -1;
        while (l<=r){
            if(nums[l]>nums[l+1])
                return l;
            else if(nums[r]>nums[r-1])
                return r;
            else{//开头和结尾都没有
                int mid = l+((r-l)>>1);
                if(nums[mid]<nums[mid+1]){
                    l = mid+1;
                }
                else if(nums[mid]<nums[mid-1]){
                    r = mid-1;
                }
                else{
                    ans = mid;
                    return mid;
                }
            }
        }
        return ans;
    }
};
