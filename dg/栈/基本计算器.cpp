//
// Created by Administrator on 24-7-17.
//
#include "string"
#include "iostream"
#include "stack"
using namespace std;
class Solution {
public:
    void _deletezero(string&s){
        int n = s.size();
        int i=0,j=0;
        while (j<n){
            if(s[j]!=' '){
                s[i]=s[j];
                ++i;
            }
            ++j;
        }
        s.erase(s.begin()+i,s.end());
    }
    int calculate(string s) {
        //删掉所有的空格
        _deletezero(s);
        //栈保留数的前置操作符
        stack<int>st;

        int ans = 0,num=0,op=1;
        st.push(op);
        for(char c:s){
            if(c>='0'){//遇到数字，需要更新num值
                num = num*10+(c-'0');
            }
            else{//遇到的不是数字
                //首先之前保留的num以及它的前置操作符op需要加到ans里面
                ans += num*op;
                num=0;
                if(c=='+'){//遇到加
                    op = st.top();
                }
                else if(c=='-'){
                    op = -st.top();
                }
                else if(c=='('){
                    st.push(op);
                }
                else
                    st.pop();
            }
        }
        return ans+op*num;
    }
};


