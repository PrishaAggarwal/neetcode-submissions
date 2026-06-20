class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        unordered_map<int,int>elements;
        while(i<n){
            elements[nums[i]]++;
            i++;
        }
        //sorting of unordered map is not possible but instead lets copy the pairs into array and sort the array and then i will pick most k frequent elements from it
        vector<pair<int,int>>sorted;
        for(auto& p:elements){
            sorted.push_back(p);
        }
        //sort(sorted.begin(),sorted.end()); 
        //here by default above code would be sorted by index and not frequency..to sort by frequency do the following
        sort(sorted.begin(),sorted.end(),
            [](auto& a,auto& b){
                return a.second>b.second;});
        // [] is called lambda and it starts a tiny anonympous function whereever u need it
        // here is if frequency of a is greater than b, then place a before b
        vector<int>ans;
        for(i=0;i<k;i++){
            ans.push_back(sorted[i].first);
        }
        return ans;
    }
};
