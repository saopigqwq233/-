struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //快慢指针，如果有环，快指针一定会追上慢指针
        if(!head||!head->next)
            return false;

        ListNode* slow = head,*fast =  head;
        while (slow&&head){
            slow = slow->next;
            head = head->next;
            if(head)
                head = head->next;
            else
                break;
            if(slow==head)
                return true;
        }
        return false;
    }
};