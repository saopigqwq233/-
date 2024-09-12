#include <cstring>
#include "Comm.h"
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int ret = 0;
        stack<int> s;
        for(auto& e:tokens){
            if(strcmp(e.c_str(),"+")==0){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(strcmp(e.c_str(),"-")==0){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(strcmp(e.c_str(),"*")==0){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if(strcmp(e.c_str(),"/")==0){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else
                s.push(stoi(e));
        }
        return s.top();
    }
};