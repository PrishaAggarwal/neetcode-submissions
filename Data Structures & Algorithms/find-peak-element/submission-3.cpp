class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid=0;
        if(n==1)
            return 0;
        while(low<=high){
            mid=low+(high-low)/2;
            if((mid+1)<n && (mid-1)>=0){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid+1]>nums[mid]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(mid+1==n && nums[mid-1]<nums[mid])
                    return mid;
                else if(mid+1==n && nums[mid-1]>nums[mid])
                    high=mid-1;
                else if((mid-1)==-1 && nums[mid]>nums[mid+1])
                    return mid;
                else
                    low=mid+1;
                
            }
        }
        return -1;
    }
};