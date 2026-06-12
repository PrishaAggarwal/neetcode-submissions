class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        vector<int> sums(n);
        int arr=0; //number of subarray
        int j=0;
        int sum=0;
        for(i=0;i<n;i++){
            if(i==0)
                sums[0]=nums[0];
            else
                sums[i]=sums[i-1]+nums[i];
        }
        sums.insert(sums.begin(), 0);
        for(j=n;j>=0;j--){
            for(i=j-1;i>=0;i--){
                sum=sums[j]-sums[i];
                if(sum==k)
                    arr++;
            }
        }
        return arr;
    }
};