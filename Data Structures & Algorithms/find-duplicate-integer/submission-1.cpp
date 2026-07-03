class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Chatgpt gave me hint that i need to see that the index that i go isnt ith index
        //Instead its the value of index i am on
        //Further i thought myself that index where the cycle of linked list starts is the repeated value in array because that is only place visited twice is the duplicate value and we would reach its index twice
        //And to find the start of cycle,we would use fyod's algo
        //This is very beautiful use/application of this algo

        int n=nums.size();
        int i=-1;
        int fast=0;
        while(i != fast){
            if(fast==0)
                i=0;
            i=nums[i];
            //Now this will create a cycle inside array and i would never be equal to n
            //We have to keep track that at what position this cycle begin
            //now here i is basically our slow pointer and fast pointer also we will introduce
            //When they meet, we recognize the cycle presence and then using cycle start detection method, we find the index where cycle starts
            // i<n inst the condition here and we will see slow and fast pointers meet or not
            fast=nums[nums[fast]];
            if(i == fast){
                i=0;
                while(i != fast){
                    i=nums[i];
                    fast=nums[fast];
                }
                return i;
            }
        }
        return -1;
    }
};