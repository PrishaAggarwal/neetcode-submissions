class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        vector<int>ans;
        int right_in=0;
        int left_in=0;
        if(n==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        if(n==1 && nums[0]==target){
            ans.push_back(right_in);
            ans.push_back(left_in);
            return ans;
        }
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                /*int lo=mid;
                while(nums[lo] == target)
                    lo--;
                ans.push_back(lo+1);
                int hi=mid;
                while(nums[hi] == target)
                    hi++;
                ans.push_back(hi-1);
                break;*/

                //HINT
                //When binary search finds target, why am I stopping ?
                //What should happen to high and low
                //Finding target values doesnt mean i found ans, it means i found candidate ans
                //you did it right,just dont do it linearly but through binary search and record it when u saw it last
                //first lets keep searching left
                int lo=low;
                int hi=mid-1;
                left_in=mid; //in case we dont find anything on left
                while(lo<=hi){
                    int mi=lo+(hi-lo)/2;
                    if(nums[mi]==target){
                        left_in=mi;
                        hi=mi-1;
                    }
                    else if(nums[mi]<target)
                        lo=mi+1;
                    else
                        hi=mi-1;
                }
                ans.push_back(left_in);
                lo=mid+1;
                hi=high;
                right_in=mid; //in case we dont find anything on right
                while(lo<=hi){
                    int mi=lo+(hi-lo)/2;
                    if(nums[mi]==target){
                        right_in=mi;
                        lo=mi+1;
                    }
                    else if(nums[mi]<target)
                        lo=mi+1;
                    else
                        hi=mi-1;
                }
                ans.push_back(right_in);
                break;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};