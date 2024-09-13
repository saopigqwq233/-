#include "Comm.h"
class Solution {
public:
    string reverseParentheses(string s) {
        string ret;
        stack<string> stack;
        for(auto&e:s){
            if(e=='('){
                stack.push(ret);
                ret = "";
            }
            else if(e==')'){
                std::reverse(ret.begin(), ret.end());
                ret = stack.top()+ret;
                stack.pop();
            }
            else{
                ret.push_back(e);
            }
        }
        return ret;
    }
//    int _f_count = 1;
//    void _reversestr(string&s,int left,int right){
//        std::reverse(s.begin()+left+1, s.begin()+right);
//        cout<<left<<','<<right<<endl;
//        s.erase(left,1);
//        s.erase(right-1,1);
//    }
//    int _reverseParentheses(string&s,int leftc,int rightc){
//        if(leftc==rightc-1){
//            s.erase(leftc,2);
//            return -2*(_f_count);
//        }
//        int l=leftc+1,r = rightc-1;
//        while (s[l]!='('&&l<r)
//            ++l;
//        while (s[r]!=')'&&r>l)
//            --r;
//        if(l==r){
//            _reversestr(s,leftc,rightc);
//            return -2*(_f_count++);
//        }
//        else
//        {
//            rightc += _reverseParentheses(s,l,r);
//            _reversestr(s,leftc,rightc);
//            return -2*(_f_count++);
//        }
//    }
//    string reverseParentheses(string s) {
//        int l=0,r = s.size()-1;
//        while (s[l]!='('&&l<r)
//            ++l;
//        while (s[r]!=')'&&r>l)
//            --r;
//        if(l==r-1){
//            s.erase(l,2);
//            return s;
//        }
//        if(l==r)
//            return s;
//
//        string ret(s);
//        _reverseParentheses(ret,l,r);
//        return ret;
//    }
};
//int main(){
//    Solution solution;
//    string s("vdgzyj()");
//    auto ret = solution.reverseParentheses(s);
//
//    cout<<ret<<endl;
//    return 0;
//}