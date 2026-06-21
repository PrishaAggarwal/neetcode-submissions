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
        while(i<n){
            key=nums[i];
            len=0;
            if(add.find(nums[i]-1) == add.end()){
                while(len<n && add.find(key) != add.end()){
                    len++;
                    key++;
                }
                i++;
            }
            else
                i++;
            max_len=max(max_len,len);
        }
        return max_len;
    }
};
