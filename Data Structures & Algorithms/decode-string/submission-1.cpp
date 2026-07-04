class Solution {
public:
    string decodeString(string s) {
        string count=""; //cant initialize count as 0 now since its a string
        stack<string>st;
        string ans;
        string temp;
        for(char c:s){
            // we put everything in stack
            //as soon as i get the first closing braket,i would pop untill i get to its corresponding opening braket
            //now we know just outside that braket we would get a number
            // we would note that number and pop it
            //then we would push the string inside those opening and closing brakets till the count is 0
            //once done we would continue on the string s
            //then it would go in loop with the count 
            count.clear(); //since count is string now
            temp.clear();
            if(c==']'){
                while(st.top() != string(1,'[')){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                while(!st.empty()  && isdigit(st.top()[0])){
                    //isalpha takes character as input and st.top is string so we convert string to char
                    //If string contains only one character then char=s[0]
                    count+=st.top();
                    st.pop();
                }
                //i kept count in string because its easier to reverse the string than a number, so after reversing i would convert it into int
                reverse(count.begin(),count.end());
                //reverse(temp.begin(),temp.end());
                int num=stoi(count);
                while(num != 0){
                    st.push(temp);
                    num--;
                }
            }
            else
                //here we are pushing char type but we actually want it to be string
                st.push(string(1,c));
                //we are making a string of length 1 with c character
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};