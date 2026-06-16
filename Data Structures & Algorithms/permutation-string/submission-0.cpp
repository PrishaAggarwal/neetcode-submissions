class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       //permutation of ABC are ABC,CBA,BCA.BAC,CAB etc.
        // Took the hint that use character frequnecy arrays
        int len1=s1.length();
        int len2=s2.length();
        int l=0;
        int r=l+len1-1;
        //lets count the frequency of all characters in s1 string first
        //lets store the frequency of letters in a hashmap
        unordered_map<char, int> freq;
        for(char c : s1) {
            //c='b'
            //c='a'
            //basically c visits each character one by one and increases frequency of that particular alphabet
            freq[c]++;
        }
        if(len2<len1) //imp case to be added 
            return false;
        unordered_map<char,int>freq_s2;
        for(int i=0;i<len1;i++){
            freq_s2[s2[i]]++;
        }
        while(r<len2){
            if(freq==freq_s2)
                return true;
            else{
                if(r==len2)
                    break;
                //have to make sure the fruencies dont go negative so
                if(freq_s2[s2[l]]==1)
                    freq_s2.erase(s2[l]); // we dont want characters with even 0 freq to be in our hashmap
                else
                    freq_s2[s2[l]]--;
                l++;
                r++;
                freq_s2[s2[r]]++;
            }
        }
        return false; 
    }
};
