class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int n=fruits.size();
        unordered_map<int,int>freq;
        int window_size=0;
        int max_fruits=0;
        while(r<n){
            freq[fruits[r]]++;
            if(freq.size()>2){
                if(freq[fruits[l]]==1)
                    freq.erase(fruits[l]);
                else
                    freq[fruits[l]]--;
                l++;
            }
            window_size=r-l+1;
            max_fruits=max(max_fruits,window_size);
            r++;
        }
        return max_fruits;
    }
};