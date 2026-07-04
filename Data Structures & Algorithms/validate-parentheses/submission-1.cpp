class Solution {
public:
    bool isOpening(char c){
        return (c=='(' || c=='{' || c=='[');
    }
    bool matches(char open,char close){
        return((open=='(' && close==')') || 
                (open=='[' && close==']') ||
                (open=='{' && close=='}')
        );
    }
    bool isValid(string s) {
        /*
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
        */



        //LOGIC 2 USING HELPER FUNCTIONS
        stack<char>st;
        for(char c:s){
            if(isOpening(c))
                st.push(c);
            else{
                if(st.empty() || !matches(st.top(),c))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
