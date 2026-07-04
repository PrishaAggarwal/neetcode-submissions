class Solution {
    public:
    //I am thinking to use helper function in order to obtain top 2 values since this code would be repeated
    pair<int,int>Top_ele(stack<int>& st){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        return {a,b};
        //always use curly brackers when returning pairs
    }
    int evalRPN(vector<string>& tokens) {
        //as we encounter numbers,we would put them in stack
        //as soon as we encounter some operation, we pop top two values 
        //apply the operation on the 2 values and push back the result into the stack
        stack<int>st;
        for(string c:tokens){
            if(c == "+"){
                auto [a,b]=Top_ele(st);
                //2 methods to get the pair results
                //2nd method is using the following
                // int a=Top_ele(st).first;
                // int b=Top_ele(st).second;
                int result=b+a;
                st.push(result);
            }
            else if(c == "-"){
                auto[a,b]=Top_ele(st);
                int result=b-a;
                st.push(result);
            }
            else if(c == "*"){
                auto[a,b]=Top_ele(st);
                int result=b*a;
                st.push(result);
            }
            else if(c == "/"){
                auto[a,b]=Top_ele(st);
                int result=b/a;
                //b is niche wala element, hence jo element phele aaya osko we divide by element jo baad mein aaya
                st.push(result);
            }
            else{
                //so out stack is int and tokens here are string to we should convert string into int before putting it into stack
                //another way is making stack string and making all variables string, but then operations can be perfromed on string so we would have to conver the numbers into int and do operations and convert into string before putting back into stack
                //its easier this way
                //stoi is used to convert string into int
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
