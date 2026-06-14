class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*int i=0;
        int n=nums.size();
        int j=0;
        int sum=0;
        int sub_len=0;
        vector<int>sum_arr(n);
        for(i=0;i<n;i++){
            if(i==0){
                sum_arr[0]=nums[0];
            }
            else
                sum_arr[i]=sum_arr[i-1]+nums[i];
        }
        sum_arr.insert(sum_arr.begin(),0);
        for(j=n;j>=0;j--){
            for(i=j-1;i>=0;i--){
                sum=sum_arr[i]-sum_arr[j];
                sub_len=j-i;
                if(sum%k==0 && sub_len>=2)
                    return true;
            }
        }
        return false;
        */
        int i=0;
        int n=nums.size();
        vector<int>sums(n);
        int rem=0;
        for(i=0;i<n;i++){
            if(i==0)
                sums[0]=nums[0];
            else 
                sums[i]=sums[i-1]+nums[i];
        } 
        unordered_map<int,int> mp;
        //mp[key]=value;
        mp[0]=-1;
        for(i=0;i<n;i++){
            rem=sums[i]%k;
            //mp.count(key);    checks if key exists (returns 0 or 1)
            if(mp.count(rem)==1){
                if((i-mp[rem])>=2)
                    return true;
            }
            else
                mp[rem]=i;
        }
        return false;
    }
};