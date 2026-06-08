class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        set<vector<int>> ans; //to store results
        //here i am using set because i dont want duplicate triplets in my ans
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(i=0;i<n-1;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    //since we are getting the ans in sorted order so order of charcters in an array is same
                    //In set {1,2,3} =! {3,2,1}
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]<0)
                    j++;
                else if(nums[i]+nums[j]+nums[k]>0)
                    k--;
            }
        }
        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};
