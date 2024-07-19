#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    //保留数字和字符串映射
    map<char,string>s;
    vector<string> ret;
    int i_ret = 0;
    //向下传递时，下一个需要知道
    //1.哪个映射关系（digits的下标-->得到char-->得到电话号码映射）
    //2.已经有的字符串

    //下一个需要做
    //1.对着拿到的下标加给tmp字符
    //2.看后面有没有电话号字符，没有就把tmp加到ret
    void _letterCombinations(string& digits,int i,string tmp){
        if(i==digits.size())
            ret[i_ret++] = std::move(tmp);

        string str = s[digits[i]];
        for (int j = 0; j < str.size(); ++j) {
            tmp.append(1,str[j]);
            _letterCombinations(digits,i+1,tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        s.insert(make_pair('2',"abc"));
        s.insert(make_pair('3',"def"));
        s.insert(make_pair('4',"ghi"));
        s.insert(make_pair('5',"jkl"));
        s.insert(make_pair('6',"mno"));
        s.insert(make_pair('7',"pqrs"));
        s.insert(make_pair('8',"tuv"));
        s.insert(make_pair('9',"wxyz"));
        ret.reserve(11665);
        _letterCombinations(digits,0,"");
        return ret;
    }
};