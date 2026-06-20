class Solution {
public:
    string minWindow(string s, string t) {
        int s_len=s.length();
        int t_len=t.length();
        if(t_len>s_len){
            return "";
        }
        string ans="";
        int l=0;
        int r=0;
        int window_size=0;
        unordered_map<char,int>t_freq;
        unordered_map<char,int>s_freq;
        for(int i=0;i<t_len;i++){
            t_freq[t[i]]++;
        }
        //lets store the window size when we get all characters of t
        //the key for that hashmap would be starting index  
        unordered_map<int,int>indices;
        while(r<s_len){
            s_freq[s[r]]++;
            if(s_freq.size()>=t_freq.size()){
                //now i would be checking the maps if they have all keys and their values in s
                bool valid=true; //to check if the whole for loop worked
                for (auto &p : t_freq){ //going through each key value pair in t_freq 
                    if (s_freq.find(p.first) == s_freq.end() || s_freq[p.first] < p.second){
                        //we use less than because the window must contain all characters...not exact those only
                        valid=false; //this show the loop didnt work
                        break;
                        //basically we are finding the key in t_freq and s_freq doesnt have that key then it returns s_freq.end() and hence our condition failed
                        //And 2nd condition is agar key exist krti hai then kya oski value diff hai ?
                        //If yes then also the end of loop
                    }
                }
                if(valid){
                    while(l <= r && (!t_freq.count(s[l]) || s_freq[s[l]] > t_freq[s[l]])){
                        //shrhinking happens when we have extra charcters 
                        //2nd condition is when we have unwanted characters that contribute to the window
                        if(s_freq[s[l]]==1)
                            s_freq.erase(s[l]);
                        else
                            s_freq[s[l]]--;
                        l++;
                    }
                    window_size=r-l+1;
                    indices[l] = window_size;
                    //now i shall make the window deliberately wrong so that it keep moving
                    s_freq[s[l]]--;
                    if(s_freq[s[l]] == 0)
                        s_freq.erase(s[l]);
                    l++;
                    r++;
                }
                else
                    r++;
            }
            else 
                r++;
        }
        int minVal=INT_MAX; //int_MAX IS LARGEST VALUE STORED IN INT
        int minKey=0;
        for (auto &p : indices) {
            if(minVal>p.second){
                minVal = p.second;
                minKey = p.first;
            }
        }
        if(indices.empty())
            return "";
        for(int i=minKey;i<(minKey+minVal);i++){
            ans+=s[i];
        }
        return ans;
    }
};
