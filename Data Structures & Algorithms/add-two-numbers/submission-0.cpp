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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* arr1=l1;
        ListNode* arr2=l2;
        ListNode* arr3=nullptr;
        ListNode* prev=nullptr;
        int y=0;
        int x=0;
        while(arr1!= nullptr || arr2 != nullptr){
            if(arr2==nullptr){
                x=arr1->val+y;
                arr1=arr1->next;
            }
            else if(arr1==nullptr){
                x=arr2->val+y;
                arr2=arr2->next;
            }
            else{
                x = arr1->val + arr2->val + y;
                arr1=arr1->next;
                arr2=arr2->next;
            }
            ListNode* temp=new ListNode(x%10);
            if(prev==nullptr){
                arr3=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=prev->next;
            }
            y=x/10;
        }
        if((arr1==nullptr && arr2==nullptr) && y>0){
            ListNode* temp=new ListNode(y);
            prev->next=temp;
            prev=temp;
        }
        return arr3;
    }
};
