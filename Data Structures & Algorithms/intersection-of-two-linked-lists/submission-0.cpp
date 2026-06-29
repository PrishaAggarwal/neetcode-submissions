/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(temp1==nullptr || temp2==nullptr)
            return nullptr;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 == temp2)
                return temp1;
            temp1=temp1->next;
            if(temp1==nullptr){
                temp1=headA;
                temp2=temp2->next;
            }
        }
        return nullptr;
    }
};