/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==nullptr)   
            return false;
        if(slow->next==nullptr)
            return false;
        while(fast != nullptr){
            slow=slow->next;
            if(fast->next==nullptr)
                return false;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};
