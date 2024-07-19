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
//class Solution {
//public:
//    ListNode* cur;
//    bool _isPalindrome(ListNode* right){
//        if(cur==right||cur==right->next)//完全成功
//            return true;
//        ListNode *tmp = cur;
//
//        if(!right->next){//最后的结点
//            return tmp->val==right->val;
//        }
//        if(_isPalindrome(right->next))
//        {
//            cur = cur->next;
//            return right->val==tmp->val;
//        }
//        else
//            return false;
//    }
//    bool isPalindrome(ListNode* head) {
//        if (!head || !head->next) {
//            return true;
//        }
//        if(!head->next->next)
//            return head->val==head->next->val;
//        cur = head;
//        return _isPalindrome(cur->next);
//    }
//};


