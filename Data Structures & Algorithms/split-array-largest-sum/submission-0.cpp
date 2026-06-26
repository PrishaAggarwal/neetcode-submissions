class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int high=accumulate(nums.begin(),nums.end(),0);
        //smallest possible ans is max of array since we cant split that element and it will be in either of array or independent array if in beginning or ending of array
        int low=0;
        int ans=0; //for candidate ans
        int split=0; //to count number of splits
        int temp_sum=0; //to record sum of splits and record the max sum in either of the split
        int max_sum=0; //to record max sum
        int arr_sum=INT_MAX;
        int i=0;
        for(i=0;i<n;i++){
            if(low<nums[i])
                low=nums[i];//sabotaged by neha,
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=mid;
            split=0;
            max_sum=0;
            temp_sum=0;
            for(i=0;i<n;i++){
                if(temp>=nums[i]){
                    temp=temp-nums[i];
                    temp_sum += nums[i];
                    if(max_sum<temp_sum){
                        max_sum=temp_sum;
                    }
                }
                else{
                    split++;
                    temp=mid;
                    i--;
                    temp_sum=0;
                }
            }
            split++;
            /*
            if(max_sum<arr_sum && split<=k)
                arr_sum=max_sum; //to record and compare between various splits
            //number of splits acc to my logic can be equal to or less than desired splits but not more than
            */
            if(split<=k){
                ans=mid;
                high=mid-1; //so that we can reduce the max_sum for split even more
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//In this idea, i am using greedy approach and trying to minimize the maximum sum of a subarray 
//sometimes it might produce less splits than required but that is a candidate since that less splits might give the max largest sum of split and manually we split into more split if required
//For example 1,0,2,3,5
//It produces at last 3 splits i.e [[1,0,2],[3],[5]] //now the splits are less but max largest sum remains 5
//Although later we can split it into 4 since k=4 like this [[1,0],[2],[3],[5]] and the ans remains same