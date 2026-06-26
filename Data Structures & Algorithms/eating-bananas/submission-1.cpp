class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n=piles.size();
        int high=0;
        int k=0;
        int i=0;
        for(i=0;i<n;i++){
            if(piles[i]>high)
                high=piles[i];
        }
        int count=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            count=0;
            for(i=0;i<n;i++){
                int temp=piles[i];
                count+=(temp+mid-1)/mid; //used for integer when u need ceil value
            }
            if(count<=h){
                k=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return k;
    }
};
