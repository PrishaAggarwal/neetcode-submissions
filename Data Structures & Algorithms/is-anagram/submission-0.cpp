class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1=s.size();
        int t1=t.size();
        unordered_map<char,int>s_freq;
        unordered_map<char,int>t_freq;
        for(int i=0;i<s1;i++){
            s_freq[s[i]]++;
        }
        for(int i=0;i<t1;i++){
            t_freq[t[i]]++;
        }
        if(s_freq==t_freq)
            return true;
        else 
            return false;
    }
};
