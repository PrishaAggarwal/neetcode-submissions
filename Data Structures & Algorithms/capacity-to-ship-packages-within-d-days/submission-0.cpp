class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        //minimum weight should be the max weight in the weights
        int i=0;
        int capacity=0;
        int low=0;
        for(i=0;i<n;i++){
            if(weights[i]>low)
                low=weights[i];
        }
        int high=accumulate(weights.begin(),weights.end(),0); //this is sum of array
        int c_days=0;
        //0 is start value of sum
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            c_days=0;
            int temp=mid;
            for(i=0;i<n;i++){
                if(temp>=weights[i]){
                    temp=temp-weights[i];
                }
                else{
                    c_days+=1;
                    temp=mid;
                    i--;
                }
            }
            c_days+=1;
            if(c_days<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};