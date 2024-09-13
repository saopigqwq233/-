//
// Created by Administrator on 24-9-13.
//
#include "Comm.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()||s.size()==1)
            return s.size();
        int max = 0;
        int begin = 0;
        int j = 0;
        unordered_map<char,int> map;
        int i = 0;
        while(begin<s.size()){
            if(map[s[begin]]!=1){
                ++map[s[begin++]];
                ++i;
            }
            else{
                if(i>max){
                    max = i;
                }
                i = 0;
                map.clear();
                begin = j++;
            }
        }
        if(i>max)
            max = i;
        return max;
    }
};
//int main(){
//    Solution s;
//    cout<<s.lengthOfLongestSubstring("abcabcd");
//    return 0;
//}

