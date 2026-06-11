class Solution {
public:
    void sortColors(vector<int>& nums) {
       int i=0;
        int j=0;
        int n=nums.size();
        int k=0;
        for(k=0;k<3;k++){
            j=i;
            while(j!=n){
                if(nums[j]==k){
                    int m=nums[i];
                    nums[i]=nums[j];
                    nums[j]=m;
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
        } 
    }
};