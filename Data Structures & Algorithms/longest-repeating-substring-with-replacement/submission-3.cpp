class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int n=s.length();
        unordered_map<char,int>count;
        int max_charfreq=0; //isko hum increase decrease nhi krenge but instead jo max vhi rehne denge becuase voh max wali ek baar toh occur hoyi thi na
        int max_len=0;
        while(r<n){
            count[s[r]]++;
            max_charfreq=max(max_charfreq,count[s[r]]);
            int window_size=r-l+1;
            if(window_size-max_charfreq>k){
                count[s[l]]--;
                l++;
            }
            window_size=r-l+1;
            max_len=max(max_len,window_size);
            r++;
        }
        return max_len;
    }
};
