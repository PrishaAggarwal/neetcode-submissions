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
        long long count=0; //it might become huge so and dont catch right ans
        //it happened for one case that if count isnt long long then ans is wrong
        while(low<=high){
            int mid=low+(high-low)/2;
            count=0;
            for(i=0;i<n;i++){
                int temp=piles[i];
                //now since temp+mid-1 might exceed the int addition so we make this calculation long long
                count+=((long long)temp+mid-1)/mid; //used for integer when u need ceil value
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
