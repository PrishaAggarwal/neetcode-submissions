class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //LOGIC 1
        /*
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
        */



        //LOGIC 2
        int i=0;
        int n=nums.size();
        unordered_map<int,int>elements;
        while(i<n){
            elements[nums[i]]++;
            i++;
        }
        vector<vector<int>>buckets(n+1);
        //we make vectors at each index, in case 2 numbers have same frequency
        for(auto& p:elements){
            //max possible frequency any element can have is n
            //here we will make bucket index=frequency
            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        int count=0; //to count k's
        for(i=n;i>=0;i--){
            if(!buckets[i].empty()){
                for(int j=0;j<buckets[i].size();j++){
                    if(count==k)
                        break;
                    ans.push_back(buckets[i][j]);
                    count++;
                    //we have to check this condition inside loop because by chance ek frequency ki 3 values aa gyi and k=2 then 3 already add ho chuki hongi and then u are checking the condition
                }
            }
        }
        return ans;
    }
};
