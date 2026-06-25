class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int num_row=matrix.size();
        int num_col=matrix[0].size();
        int n=num_row*num_col;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val = matrix[mid / num_col][mid % num_col]; //got this conversion from claude
            //converts into matrix row and col
            if(val==target)
                return true;
            else if(val>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};
