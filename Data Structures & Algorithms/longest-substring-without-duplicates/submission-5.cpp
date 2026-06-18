class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int len=s.length();
        int r=1;
        int max_len=0;
        int tem_len=0;
        unordered_map<char,int>freq_s;
        if(len==1)
            return 1;
        if(len==0)
            return 0;
        freq_s[s[0]]++;
        while(r<len){
            if(l==0 && r==1){
                if(s[r]!=s[l]){
                    freq_s[s[r]]++;
                    tem_len=2;
                    r++;
                }
                else{
                    l++;
                    r=l+1;
                    tem_len=1;
                }
            }
            else{
                if(freq_s[s[r]]==0){
                    freq_s[s[r]]++;
                    tem_len++;
                }
                else{
                    while(s[l]!=s[r]){
                        freq_s.erase(s[l]);
                        l++;
                    }
                    l++;
                    tem_len=r-l+1;
                }
                r++;
            }
            max_len=max(max_len,tem_len);
        }
        return max_len;
    }
};
