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
    bool isPalindrome(ListNode* head) {
        //let me reach middle of list and then i would reset the fast pointer to head
        //now i know the end of 2nd LL, i would reverse it
        //After revering i would break the two LL and compare
        //and then i would do comparision till the end
        //Revering i was thinking but chatgpt said go ahead
        
        //since i want the slow pointer to be one back then what is required because first i would make that position's next to nullptr to break and then go the position where i want my 2nd array to start
        ListNode* slow=new ListNode(0); //correct way to make a dummy pointer
        slow->next=head;
        ListNode* fast=slow;
        if(head->next == nullptr)   
            return true;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //if(fast->next == nullptr)
        //   slow=slow->next;
        fast=head;
        ListNode* arr2=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(arr2 != nullptr){
            ListNode* front=arr2->next;
            arr2->next=prev;
            prev=arr2;
            arr2=front;
        }
        ListNode* arr2_head=prev;
        ListNode* temp=fast;
        ListNode* temp2=prev;
        while(temp != nullptr && temp2 != nullptr){
            if(temp->val == temp2->val){
                temp=temp->next;
                temp2=temp2->next;
            }
            else
                return false;
        }
        return true;
    }
};