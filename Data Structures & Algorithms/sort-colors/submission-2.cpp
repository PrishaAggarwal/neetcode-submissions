class Solution {
public:
    void sortColors(vector<int>& nums) {
        //LOGIC 1
        /*
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
        */




        //LOGIC 2
        int i=0;
        int l=0;
        int n=nums.size();
        int r=n-1;
        while(i<=r){
            if(nums[i]==0){
                int m=nums[l];
                nums[l]=nums[i];
                nums[i]=m;
                l++;
                i++;
            }
            else if(nums[i]==2){
                if(nums[r]==2)
                    r--;
                else{
                    int m=nums[r];
                    nums[r]=nums[i];
                    nums[i]=m;
                    r--;
                    if(m != 0)
                        i++;
                }
            }
            else{
                i++;
            }
        }
    }
};