class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int window_size=1; //here variable window size is ans
        int l=0;
        int r=0;
        //stack<int>large; //top pr sabse bada
        //stack<int>small; //top pr sabse chotta
        //we are storing indices taki agar koi element out of bounds jaye then we can remove it 
        //now we would use deque because we want to remove the elements from bottom also if they are out of bounds
        deque<int>dq_large;
        deque<int>dq_small;
        dq_large.push_back(0);
        dq_small.push_back(0);
        //both large and small deque would be monotonic so that we get the smallest and largest value in window
        int diff=0;
        int max_ws=1;
        int n=nums.size();
        bool valid=true;
        if(n==1){
            return 1;
        }
        while(l<=r){
            if(l==r){
                //do nothing
                //because yeh wala element already dono mein hoga so we dont want duplicates
            }
            else if(valid){
                //lets write code for large deque first
                if(nums[dq_large.back()]>=nums[r]){
                    dq_large.push_back(r);
                }
                else{
                    while(!dq_large.empty() && nums[dq_large.back()]<nums[r]){
                        dq_large.pop_back();
                    }
                    dq_large.push_back(r);
                }
                //small deque code
                if(nums[dq_small.back()]>nums[r]){
                    while(!dq_small.empty() && nums[dq_small.back()]>nums[r]){
                        dq_small.pop_back();
                    }
                    dq_small.push_back(r);
                }
                else{
                    dq_small.push_back(r);
                }
            }
            diff=nums[dq_large.front()]-nums[dq_small.front()];

            //i need to put condition here about if whole array is our ans and r has reached n-1 and l is still at l=0
            if(diff<=limit){
                if(r==(n-1)){
                    if(max_ws<=window_size){
                        return window_size;
                    }
                    else{
                        return max_ws;
                    }
                }
                window_size++;
                r++;
                valid=true;
            }
            else{
                if(dq_large.front()==l){
                    dq_large.pop_front();
                }
                if(dq_small.front()==l){
                    dq_small.pop_front();
                }
                if(max_ws<window_size-1){
                    max_ws=window_size-1;
                    // -1 because we have a size bigger of window_size that didnt work
                }
                l++;
                //since l incremented so bool valid is false and hence no changes in the deque
                valid=false;
                window_size--;
                if(r==(n-1)){
                    if(window_size>=max_ws){
                        return window_size;
                    }
                    else{
                        return max_ws;
                    }
                }
            }
        }
        return max_ws;
    }
};
//chatgpt told me that during duplicates storing values can be harmful since we dont know which index value we removed so i should store indices so i stores indices

//i realised it by dry running that if l has been incremented then also hum adding everything to deque wala step miss krenge and for that we introduce a new variable