class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        vector<int> ans;
        //store the complement in hashmap
        //took this hint and now i can do this ques
        //i got it now, see iterating through values take O(n) time but iterating through key doesnt
        //so i have to now store them in opp way then what i was doing
        unordered_map<int,int>comp;
        int m=0;
        for(int i=0;i<n;i++){
            m=target-nums[i];
            //i will use insert so that old value doesnt get overwritten and i need smallest index
            comp.insert({m,i});
            //insert adds only if we have new key
            // also its format is map.insert({key,value})
        }
        int tem_comp=0;
        while(l<n){
            if(comp.find(nums[l]) != comp.end()){
                ans.push_back(l);
                //if i found the key...access its value like comp[tem_comp]
                // .second is used on pair...that is when we are iterating through the map..pair by pair
                //here . second cant be used on whole map so we access value in the map
                ans.push_back(comp[nums[l]]);
                if(ans[0]==ans[1]){ //checking ki same index toh store nhi ho gya
                    l++;
                    ans.clear(); //if same index then clear the array
                }
                else
                    break;
            }
            else 
                l++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
