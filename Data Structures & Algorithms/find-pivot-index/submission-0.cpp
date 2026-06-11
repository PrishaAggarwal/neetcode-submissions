class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int> sums(n);
        int index=0;
        int left_sum=0;
        int right_sum=0;
        for(i=0;i<n;i++){
            if(i==0)
                sums[0]=nums[0];
            else
                sums[i]=sums[i-1]+nums[i];
        }
        for(i=0;i<n;i++){
            if(i==0){
                left_sum=0;
                right_sum=sums[n-1]-sums[0];
            }
            else if(i==(n-1)){
                right_sum=0;
                left_sum=sums[n-2];
            }
            else{
                right_sum=sums[i-1];
                left_sum=sums[n-1]-sums[i];
            }
            if(right_sum==left_sum){
                index=i;
                return index;
            }
        }
        return -1;
    }
};