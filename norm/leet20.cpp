#include "Comm.h"
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1)
            return false;
        stack<char> stack;
        for(auto e:s){
            if(e=='('||e=='['||e=='{'){
                stack.push(e);
            }
            else if(e==')'||e==']'||e=='}'){
                if(stack.empty())
                    return false;
                char tmp = stack.top();
                stack.pop();
                if(e==')'&&tmp!='(')
                    return false;
                if(e==']'&&tmp!='[')
                    return false;
                if(e=='}'&&tmp!='{')
                    return false;
            }
        }
        return stack.size()==0;
    }
};
//int main(){
//    string string1("()");
//    Solution s;
//    s.isValid(string1);
//}