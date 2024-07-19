#include "iostream"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//递归思路：
//1.外部变量保存前半部分结点
//2.递归到最后开始比较

class Solution {
public:
    ListNode* cur;
    bool flag;
    void _isPalindrome(ListNode* right){
        if(!right->next){//最后的结点
            flag = (cur->val==right->val);
            cur = cur->next;
            return;
        }
        _isPalindrome(right->next);
        //错误
        if(!flag)
            return;
        //若之前正确
        flag = (cur->val==right->val);
        if(!flag){//有错误
            return;
        } else{
            cur = cur->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        if(!head->next->next)
            return head->val==head->next->val;
        flag = true;
        cur = head;
        _isPalindrome(cur->next);
        return flag;
    }
};







//#include <iostream>
//#include "string"
//#include "vector"
//#include "map"
//
//using namespace std;
//
////为什么不信，ret.reserve()
////然后ret[i_ret++]=tmp;
//class Solution {
//public:
//    //保留数字和字符串映射
//    map<char,string>s;
//    vector<string> ret;
//    int i_ret = 0;
//    //向下传递时，下一个需要知道
//    //1.哪个映射关系（digits的下标-->得到char-->得到电话号码映射）
//    //2.已经有的字符串
//
//    //下一个需要做
//    //1.对着拿到的下标加给tmp字符
//    //2.看后面有没有电话号字符，没有就把tmp加到ret
//    void _letterCombinations(const string& digits,int i,string& tmp){
//        if(i==digits.size())
//            ret.push_back(tmp);
//
//        string str = s[digits[i]];
//        for (int j = 0; j < str.size(); ++j) {
//            tmp.append(1,str[j]);
//            _letterCombinations(digits,i+1,tmp);
//            tmp.pop_back();
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//        if(digits.size()==0)
//            return vector<string>();
//        s.insert(make_pair('2',"abc"));
//        s.insert(make_pair('3',"def"));
//        s.insert(make_pair('4',"ghi"));
//        s.insert(make_pair('5',"jkl"));
//        s.insert(make_pair('6',"mno"));
//        s.insert(make_pair('7',"pqrs"));
//        s.insert(make_pair('8',"tuv"));
//        s.insert(make_pair('9',"wxyz"));
//        string tmp;
//        _letterCombinations(digits,0,tmp);
//        return ret;
//    }
//};
//
//int main(){
//    string dig = "23";
//    Solution s;
//    auto ret = s.letterCombinations(dig);
//    for(auto &s:ret){
//        cout<<s<<' ';
//    }
//    return 0;
//}



//#include "iostream"
//
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//ListNode* create(int a[],int n){
//    ListNode*ret;
//    ListNode*p;
//    for(int i=0;i<n;i++){
//        if(!ret){
//            ret = new ListNode(a[i]);
//            p = ret;
//            continue;
//        }
//        p->next = new ListNode(a[i]);
//        p = p->next;
//    }
//    return ret;
//}
//void PrintDebug(ListNode*l){
//    while (l){
//        cout<<l->val<<' ';
//        l = l->next;
//    }
//    cout<<endl;
//}
//class Solution {
//public:
//    void _reverse(ListNode*begin,ListNode*end){
//        if(begin==end)
//            return;
//        if(begin->next==end) {
//            end->next = begin;
//            return;
//        }
//        ListNode*next = begin->next;
//        _reverse(begin->next,end);
//        next->next = begin;
//    }
//
//    ListNode* _reverseKGroup(ListNode*prev,ListNode*begin,ListNode*end,ListNode*next){
//        _reverse(begin,end);
//        begin->next = next;
//        if(prev)
//            prev->next = end;
//
//        return begin;
//    }
//
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        int cnt = 0;
//        ListNode*begin = head;
//        ListNode*end = head;
//        ListNode*ret;
//        for(;end;end=end->next){
//            ++cnt;
//            if(cnt%k==0){
//                begin = _reverseKGroup(nullptr,begin,end,end->next);
//                ret = end;
//                end = begin->next;
//                break;
//            }
//        }
//        for(;end;){
//            ++cnt;
//            if(cnt%k==0){
//                begin = _reverseKGroup(begin,begin->next,end,end->next);
//                end = begin->next;
//            }
//            else
//                end = end->next;
//        }
//        return ret;
//    }
//};
//
//int main(){
//    int a[5]={1,2,3,4,5};
//    ListNode *l = create(a,5);
//    PrintDebug(l);
//    Solution s;
//    l = s.reverseKGroup(l,2);
//    PrintDebug(l);
//    return 0;
//}