struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//递归：定义一个全局静态变量，先递归到最后一个结点，返回时检查全局变量看看是否==n，不是就+1返回。

//双指针，快指针先跑n个结点，然后前后指针一起遍历
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*left = head;
        for (int i = 0; i < n; ++i) {
            left = left->next;
        }

        ListNode*prev = nullptr;
        ListNode*cur = head;
        while (left){
            prev = cur;
            cur = cur->next;
            left = left->next;
        }
        if(prev){
            prev->next = cur->next;
            delete cur;
            return head;
        }
        else{
            //遇到删头结点的情况记得更新头结点
            head = cur->next;
            delete cur;
            return nullptr;
        }
    }
};