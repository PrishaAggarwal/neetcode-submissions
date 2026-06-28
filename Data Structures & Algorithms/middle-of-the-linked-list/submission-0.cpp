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
    ListNode* middleNode(ListNode* head) {
        //got hint to use fast and slow pointers
        //got an idea that if i start both at start of array then when fast reaches end of list then slow would have reached only middle of array because slow covers half the diff fast has covered
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};