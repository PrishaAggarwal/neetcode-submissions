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
        /*
        //LOGIC 1
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
        */








        //LOGIC 2
        ListNode* left=nullptr;
        ListNode* f_head=head;
        //This is single pass ans
        // A pass is full traversal of entire list
        //My ans uses 2 passes and this ans uses one pass
        //number of while loop is not equal to number of passes 
        //Putting right pointer to n times right of left pointer is basically initialization within same loop conceptually
        ListNode* right=head;
        if(head == nullptr)
            return f_head;
        int k=0;
        while(k != n){
            right=right->next;
            k++;
        }
        if(f_head->next==nullptr){
            f_head=nullptr;
            return f_head;
        }
        if(right==nullptr){
            f_head=f_head->next;
            return f_head;
        }
        while(right != nullptr){
            if(left==nullptr)
                left=f_head;
            else
                left=left->next;
            right=right->next;
        }
        left->next=left->next->next;
        return f_head;
    }
};

//LOGIC 1 IS COMPLETELY CORRECT AND PASSES ALL TEST CASES BUT WHAT IF INTERVIEWER ASKS FOR TO DO THIS QUES IN ONE PASS
//LOGIC 2
//what we do is, we use 2 pointers...1st pointer is at beginning of list and right pointer is shifted by 2 if n=2
//Like for example put left at 1st position and right at 3rd position
//shift each pointer by one till r reaches nullptr
// then by now left will reach nth node from end
//we wanna delete this node now..but we need prev node's help in doing that
//we we instead of starting left from head, we start from dummy node/nullptr
//we will return dummy ka next wala pointer because that would be start pointer