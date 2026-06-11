class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int k=0; //number of zeroes
        while(j!=n){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
                j++;
            }
            else{
                k++;
                j++;
            }
        }
        for(i=i;i<n;i++){
            nums[i]=0;
        }
    }
};