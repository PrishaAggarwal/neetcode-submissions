class Solution {
public:
    bool isPalindrome(string s) {
                string result ="";
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
            return false; 
    }
};
