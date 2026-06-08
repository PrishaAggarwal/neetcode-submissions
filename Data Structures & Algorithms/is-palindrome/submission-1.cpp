class Solution {
public:
    bool isPalindrome(string s) {
                /*string result ="";
        for(char c:s){
            if(isalnum(c)){
                c=tolower(c);
                result+=c;
            }

        }
        string original=result; //we dont have to compare with original, we have to compare clean string with clean reverse string
        reverse(result.begin(),result.end());
        if (original==result)
            return true;
        else
            return false; */
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(isalnum(s[i]) && isalnum(s[j])){
                s[i]=tolower(s[i]);
                s[j]=tolower(s[j]);
                if(s[i]==s[j]){
                    i++;
                    j--;
                }
                else
                    return false;
            }
            else if(!isalnum(s[i])){
            // using ! operator to say 'not'
                i++;
            }
            else
                j--;
        }
        return true;
    }
};
