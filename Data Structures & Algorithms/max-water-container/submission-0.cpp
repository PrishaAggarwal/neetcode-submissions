class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int max_ans=0;
        while(i<j){
            int ans=min(heights[i],heights[j])*(j-i);
            if(max_ans<ans)
                max_ans=ans;
            else
                ans=ans;
            if(heights[i]<heights[j])
                i++;
            else
                j--;
        }
        return max_ans;
    }
};
