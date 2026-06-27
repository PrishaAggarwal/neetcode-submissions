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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* head2=list2;
        //ListNode* f_head=nullptr;
        ListNode* f_head = new ListNode(0); //because i am trying to access this node's val later and that gives me error so it has to be initialized it because you need an actual node that f_head points to.
        ListNode* curr=nullptr;
        
        //keeping the edge case where list 1 and list 2 both are nullptr;
        if(head1==nullptr && head2==nullptr){
            ListNode* temp=nullptr;
            return temp;
        }

        //another edge case where ek list phele hi null hai
        if(head1 == nullptr){
            ListNode* f_head=head2;
            curr=f_head;
            head2=head2->next;
            while(head2 != nullptr){
                ListNode* temp= new ListNode(head2->val);
                curr->next=temp;
                curr=curr->next;
                head2=head2->next;
            }
            curr->next=nullptr;
            return f_head;
        }
        if(head2 == nullptr){
            ListNode* f_head=head1;
            curr=f_head;
            head1=head1->next;
            while(head1 != nullptr){
                ListNode* temp= new ListNode(head1->val);
                curr->next=temp;
                curr=curr->next;
                head1=head1->next;
            }
            curr->next=nullptr;
            return f_head;
        }
        if(head1->val <= head2->val){
            f_head->val=head1->val;
            head1=head1->next;
        }
        else{
            f_head->val=head2->val;
            head2=head2->next;
        }
        //let curr be pointer for our final array
        curr=f_head;
        //we have to think of a case where one of the LL ends and other doesnt end and we have to just copy its content into final LL later
        while(head1 != nullptr || head2 != nullptr){
            if(head1 == nullptr){
                ListNode* temp= new ListNode(head2->val);
                curr->next=temp;
                curr=curr->next;
                head2=head2->next;
            }
            else if(head2 == nullptr){
                ListNode* temp= new ListNode(head1->val);
                curr->next=temp;
                curr=curr->next;
                head1=head1->next;
            }
            else if(head1-> val <= head2->val){
                ListNode* temp= new ListNode(head1->val);
                curr->next=temp;
                curr=curr->next;
                head1=head1->next;
            }
            else{
                ListNode* temp=new ListNode(head2->val);
                curr->next=temp;
                curr=curr->next;
                head2=head2->next;
            }
        }
        curr->next=nullptr;
        return f_head;
    }
};
