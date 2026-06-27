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


        //ListNode* f_head = new ListNode(0); 

        //because i am trying to access this node's val later and that gives me error so it has to be initialized it because you need an actual node that f_head points to.

        //but now i am reusing nodes so i can define it as nullptr
        ListNode* f_head=nullptr;
        ListNode* curr=nullptr;
        ListNode* temp= nullptr;
        
        //keeping the edge case where list 1 and list 2 both are nullptr;
        if(head1==nullptr && head2==nullptr){
            ListNode* temp=nullptr;
            return temp;
        }

        //another edge case where ek list phele hi null hai
        /*if(head1 == nullptr){
            //ListNode* f_head=head1;
            f_head=head2;
            curr=f_head;
            head2=head2->next;
            while(head2 != nullptr){
                //ListNode* temp= new ListNode(head2->val);
                temp=head2;
                curr->next=temp;
                curr=curr->next;
                head2=head2->next;
            }
            //curr->next=nullptr;
            //not needed since if u pass one value then constructor automatically does it
            return f_head;
        }
        
        

        if(head2 == nullptr){
            //ListNode* f_head=head1;
            f_head=head1;
            curr=f_head;
            head1=head1->next;
            while(head1 != nullptr){
                //ListNode* temp= new ListNode(head1->val);
                temp=head1;
                curr->next=temp;
                curr=curr->next;
                head1=head1->next;
            }
            //curr->next=nullptr;
            return f_head;
        }
        */




        //No need to tranverse whole LL...just point your returning head to the list's head u wanna return
        //If list1 is already nullptr, isn't list2 already the exact linked list I want to return?

        if(head1 == nullptr){
            f_head=head2;
            return f_head;
        }
        if(head2==nullptr){
            f_head=head1;
            return f_head;
        }


        if(head1->val <= head2->val){
            //f_head->val=head1->val;
            //in above i dont need to copy the data and instead reuse the node
            f_head=head1;
            head1=head1->next;
        }
        else{
            //f_head->val=head2->val;
            f_head=head2;
            head2=head2->next;
        }
        //let curr be pointer for our final array
        curr=f_head;
        //we have to think of a case where one of the LL ends and other doesnt end and we have to just copy its content into final LL later



        //while(head1 != nullptr || head2 != nullptr){
        //I am going to make this condition and...dekho agar ek bhi khtm ho gya then at last bas ek hi hoga jo null nhi hoga
        //toh bas oss remaining LL ke elements ko final LL mein daldo without this while or any extra while loop
        //remaning puri LL kyu hi tranverse krni hai
        while(head1 != nullptr && head2 != nullptr){
            /*
            if(head1 == nullptr){
                //ListNode* temp= new ListNode(head2->val);
                temp=head2;
                curr->next=temp;
                curr=curr->next;
                head2=head2->next;
            }
            else if(head2 == nullptr){
                //ListNode* temp= new ListNode(head1->val);
                temp=head1;
                curr->next=temp;
                curr=curr->next;
                head1=head1->next;
            }
            */

            //else if(head1-> val <= head2->val){
            if(head1-> val <= head2->val){
                //ListNode* temp= new ListNode(head1->val);
                temp=head1;
                curr->next=temp;
                curr=curr->next;
                head1=head1->next;
            }
            else{
                //ListNode* temp=new ListNode(head2->val);
                temp=head2;
                curr->next=temp;
                curr=curr->next;
                head2=head2->next;
            }
        }
        if(head1 == nullptr){
            curr->next=head2;
        }
        if(head2==nullptr){
            curr->next=head1;
        }
        //curr->next=nullptr;
        return f_head;
    }
};

//My code passed all test cases but beats only 4 percent in run time
//It is because my implement includes new and creates new nodes everytime and creating new nodes in memory is expensive and take alot of runtime
//I am going to try and remove new and use the existing nodes