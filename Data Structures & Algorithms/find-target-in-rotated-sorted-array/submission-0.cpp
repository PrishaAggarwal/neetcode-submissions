class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid=INT_MAX;
        int low=0;
        int n=nums.size();
        int act_mid=low+((n-1)-low)/2;
        //lets search for smallest element in array on left of mid
        int mid_arr=act_mid;
        mid=act_mid;
        int high=mid;
        while(low<=high){
            act_mid=low+(high-low)/2;
            if(nums[act_mid]<nums[mid]){
                mid=act_mid;
            }
            high=high-1;
        }
        //now lets see right side pr agar we get smallest element
        low=mid_arr;
        high=n-1;
        while(low<=high){
            act_mid=low+(high-low)/2;
            if(nums[act_mid]<nums[mid]){
                mid=act_mid;
            }
            low=low+1;
        }
        // we now have smallest element in the array that is actual starting index 
        //we have now 2 seperate arrays in which we have to find the number
        //arr1
        int lo=0;
        int hi=mid-1;
        int mi=0;
        while(lo<=hi){
            mi=lo+(hi-lo)/2;
            if(nums[mi]==target)
                return mi;
            else if(nums[mi]<target)
                lo=mi+1;
            else
                hi=mi-1;
        }
        lo=mid;
        hi=n-1;
        mi=0;
        while(lo<=hi){
            mi=lo+(hi-lo)/2;
            if(nums[mi]==target)
                return mi;
            else if(nums[mi]<target)
                lo=mi+1;
            else
                hi=mi-1;
        }
        return -1;
    }
};
