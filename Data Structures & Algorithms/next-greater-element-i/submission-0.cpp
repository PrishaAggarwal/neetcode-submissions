class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //what i am going to do is firstly i would find next greater element of all elements in num2
        //I would store the next greater element in hashmap
        //Then later i would find the indices of elements of num1 in hashmap and final ans is thashmap ki corresponding value
        //agar koi element is not present in keys of hashmap then we would its ans is -1 automatically

        //to find greater element i would traverse right to left and use stack
        stack<int>values;
        int n2=nums2.size();
        int n1=nums1.size();
        vector<int>ans(n1,-1);
        unordered_map<int,int>temp;
        int i=0;
        for(i=n2-1;i>=0;i--){
            if(values.empty()){
                values.push(nums2[i]);
                temp[nums2[i]]=-1;
            }
            else{
                while(!values.empty() && values.top()<nums2[i]){
                    values.pop();
                }
                if(!values.empty())
                    temp[nums2[i]]=values.top();
                else
                    temp[nums2[i]]=-1;
                values.push(nums2[i]);
            }
        }
        //now we know next greater element of all elements in nums2
        //We would find index of nums1 in hashmap's key and value would be our result
        for(i=0;i<n1;i++){
            if(temp.find(nums1[i]) == temp.end()){
                ans[i]=-1;
            }
            else{
                ans[i]=temp[nums1[i]];
            }
        }
        return ans;
    }
};