class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=l+k-1;
        int n=nums.size();
        deque<int> elem_max;
        vector<int> indices;
        while(l<=r){
            if(l==0){
                elem_max.push_back(nums[0]);
            }
            else if(elem_max.back()>=nums[l]){
                elem_max.push_back(nums[l]);
            }
            else{
                while(!elem_max.empty() && elem_max.back()<nums[l]){
                    elem_max.pop_back();
                }
                elem_max.push_back(nums[l]);
            }
            l++;
        }
        indices.push_back(elem_max.front());
        l=1;
        r++;
        while(r<n){
            if(elem_max[0]==nums[l-1])
                elem_max.pop_front();
            if(nums[r]<=elem_max.back()){  
                elem_max.push_back(nums[r]);
            }
            else{
                while(!elem_max.empty() && elem_max.back()<nums[r]){
                    elem_max.pop_back();
                }
                elem_max.push_back(nums[r]);
            }
            indices.push_back(elem_max.front());
            l++;
            r++;
        }
        return indices;
    }
};
