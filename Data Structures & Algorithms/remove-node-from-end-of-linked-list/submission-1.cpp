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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* f_head=head;
        int length=0;
        while(curr!=nullptr){
            curr=curr->next;
            length++;
        }
        if(length==0){
            return f_head;
        }
        if(length==1){
            f_head=nullptr;
            return f_head;
        }
        curr=head;
        //now jo node position we know, osko remove kr denge
        //to if the position of node we are on....we use k
        int k=1;
        int remove=length-n+1;
        ListNode* prev=nullptr;
        while(curr != nullptr){
            if(k==remove){
                if(curr==head){
                    f_head=curr->next;
                }
                else
                    prev->next=curr->next;
                break;
            }
            prev=curr;
            curr=curr->next;
            k++;
        }
        return f_head;
    }
};
