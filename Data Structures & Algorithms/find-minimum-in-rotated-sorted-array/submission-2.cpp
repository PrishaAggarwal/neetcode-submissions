class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid=0;
        if(n==1){
            mid=nums[0];
            return mid;
        }
        if(n==0){
            mid=-1;
            return mid;
        }
        while(low<high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        return nums[low];
    }
};
