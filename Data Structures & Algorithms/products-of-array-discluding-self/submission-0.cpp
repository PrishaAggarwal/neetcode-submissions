class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        vector<int>answer(n);
        vector<int>suffix(n);
        vector<int>prefix(n);
        //lets calculate just suffix for each number
        for(j=n-1;j>=0;j--){
            if(j==n-1)
                suffix[j]=1;
            else
                suffix[j] = suffix[j+1]* nums[j+1];
        }
        for(i=0;i<n;i++){
            if(i==0)
                prefix[i]=1;
            else 
                prefix[i]= prefix[i-1]*nums[i-1];
        }
        for(i=0;i<n;i++){
            answer[i]=prefix[i]*suffix[i];
        }
        return answer;
    }
};
