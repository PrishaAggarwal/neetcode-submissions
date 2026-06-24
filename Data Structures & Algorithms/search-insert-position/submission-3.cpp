class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid=0;
        if(target>nums[high])
            return n;
        if(target<nums[low])
            return 0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
                if(high==low)
                    return low+1;
                if(high<low)
                    return high+1;
            }
        }
        return -1;
    }
};