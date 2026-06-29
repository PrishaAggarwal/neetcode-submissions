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
    void reorderList(ListNode* head) {
        //got an idea, what if i partition the LL into half from the middle
        //then i would one element from each LL and create the final LL
        ListNode* slow=new ListNode(0);
        slow->next=head;
        ListNode* fast=slow;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* arr2=slow->next;
        slow->next=nullptr;
        //lets reverse the 2nd array now before using it
        //i am reusing the pointers
        slow=head;
        fast=arr2;
        ListNode* prev=nullptr;
        while(fast != nullptr){
            ListNode* front=fast->next;
            fast->next=prev;
            prev=fast;
            fast=front;
        }
        //now head of array is prev so
        arr2=prev;
        fast=arr2; //reusing the pointer again
        while(slow != nullptr && fast != nullptr){
            ListNode* temp=slow->next;
            slow->next=fast;
            ListNode* temp2=fast->next;
            fast->next=temp;
            slow=temp;
            fast=temp2;
        }
    }
};
