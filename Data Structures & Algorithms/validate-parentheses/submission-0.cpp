class Solution {
public:
    bool isValid(string s) {
        //LOGIC 1 USING HASHMAP
        stack<char>st;
        unordered_map<char,char>mp={
            {')','('},
            {'}','{'},
            {']','['}
        };
        for(char c:s){
            if(mp.find(c) == mp.end())
                st.push(c);
            else{
                if(st.empty() || st.top()  != mp[c])    
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
