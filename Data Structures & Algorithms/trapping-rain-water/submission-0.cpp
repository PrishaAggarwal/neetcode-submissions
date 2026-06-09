class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
        int left_max=0;
        int right_max=0;
        int k=0; //current index we are scanning
        int total_water=0;
        int water=0;
        for(k=0;k<n-1;k++){
            left_max=0;
            right_max=0;
            int i=0;
            int j=0;
            //for left side
            for(i=0;i<k;i++){
                left_max=max(left_max,height[i]);
            }
            for(j=k;j<n;j++){
                right_max=max(right_max,height[j]);
            }
            water=min(left_max,right_max)-height[k]; //just in case k height is bigger then water cant be negative
            if(water>0)
                total_water=total_water+water;
        }
        return total_water; 
    }
};
