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
        //LOGIC 1
        /*
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
        */




        //LOGIC 2
        //from video
        //Easiest method is to make use to hashset
        //go go through 1st LL, and store all nodes of it
        //Then go through 2nd LL, the first that matches hashset of 1st LL gives our ans 
        //This approach obv takes up extra space


        //Now another approach
        //One of the lists is longer than other, we know that if they intersect then they would end at the same node
        //Start a pointer at head of list1 and similarly at head of list2
        //Increment the B pointer by the diff between the length of lists
        //Once done then start the algo and compare the nodes of both lists if they are same or not
        //If not then increment both pointers



        //MORE ELEGANT SOLUTION WHERE WE USE LENGTHS BUT DONT ACTUALLY HAVE TO FIND LENGTH OF LISTS
        //Lets say we had a pointer at start of list1 and increment it by 5
        //When we reach nullptr(i.e end of list1)
        //Then we go to B and go through 6 spots untill we get back to null
        //5+6
        //What if we do this thing again, but this time we start at B list, and reach end
        //On reaching end, we go on the other list
        //This also 5+6
        //The two pointers that we had diff starting points are going to intersept at the end of list i.e nullptr
        //Both intersept after 11 spaces
        //Hence 10 spaces ke baad they were at c3
        //So on....at 8 spaces, they would have intersected at c1
        //The time they intersected is going to be the result




        //TOH BASICALLY WE USED LL TO OUR ADVANTAGE
        //LETS SAY WHEN THE TWO POINTERS STARTED, ARR1 POINTER AT HEAD1
        //ARR2 POINTER AT HEAD2
        //ON INCREAMING AGAIN AND AGAIN
        //WE GET TO A POINT WHEN ARR1 IS NULLPTR AND ARR2 IS AT C3
        //WE SET ARR1 TO HEAD2 AND AGAIN INCREMENT NOW
        //NOW ARR1 IS AT B2 AND ARR2 IS AT NULLPTR AND HENCE WE SET IT TO HEAD1
        //NOW IF YOU SEE THEN BOTH THE POINTERS ARE AT PARALLEL LENGTH TO EACH OTHER AND WE COMPARE THE NODES AND FIND THE INTERSECTION
        //The node are parallel to each other because both nodes travel exactly length(A)+length(B)
        ListNode* arr1=headA;
        ListNode* arr2=headB;
        while(arr1 != arr2){
            if(arr1==nullptr)
                arr1=headB;
            else if(arr2==nullptr)
                arr2=headA;
            else{
                arr1=arr1->next;
                arr2=arr2->next;
            }
            if(arr1 == arr2){
                return arr1;
            }
        }
        return nullptr;
    }
};
//LOGIC 1 PASSES ALL TEST CASES BUT HAS TIME COMPLEXITY OF O(M*N) AND NEEDED TIME COMPLECITY IS O(M+N)