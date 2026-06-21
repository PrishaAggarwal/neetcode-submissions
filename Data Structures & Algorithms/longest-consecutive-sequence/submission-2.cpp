class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        unordered_set<int>add; 
        //i can just store the array into this and dont need anything to stored along side
        //unordered_set best when u only care about existance
        int temp=0;
        int len=0;
        int max_len=0;
        while(i<n){
            add.insert(nums[i]);
            i++;
        }
        i=0;
        int key=0;
        for(int num:add){
            key=num;
            len=0;
            if(add.find(num-1) == add.end()){
                while(add.find(key) != add.end()){
                    len++;
                    key++;
                }
            }
            max_len=max(max_len,len);
        }
        return max_len;
    }
};
