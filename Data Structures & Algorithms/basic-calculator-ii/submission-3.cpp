class Solution {
public:
    int calculate(string s) {
        stack<string>st;
        int i=0;
        string temp;
        char operation; //to store what operation we have to perform
        bool valid=false; //to see if operation has to be performed or not
        int temp1=0;
        int temp2=0;
        while(i<s.length()){
            while(s[i]== ' ')
                i++;
            temp=s[i];
            //lets extract numbers first
            i++;
            while(s[i]== ' ')
                i++;
            while(i<s.length() && s[i] != '+' && s[i] != '*' && s[i] != '-' && s[i] != '/' && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(valid){
                //now we have 2 number..one on top of stack and one in temp
                //since we have the operation as multiplication or division so we perform it here and push the result to the top of stack
                if(operation == '*'){
                    temp1=stoi(st.top());
                    st.pop();
                    temp2=stoi(temp);
                    long long ans=temp1*temp2;
                    st.push(to_string(ans));
                }
                else if(operation == '/'){
                    temp1=stoi(st.top());
                    st.pop();
                    temp2=stoi(temp);
                    int ans=temp1/temp2;
                    st.push(to_string(ans));
                }
                valid=false;
            }
            else{
                st.push(temp);
                //since no operation was performed so we put the number on top of stack
            }
            temp.clear();
            //now chahe jitne marzi digits ka number ho, its now in the stack top
            //aab we check for division and multiplication
            if(i<s.length()){
                while(s[i]== ' ')
                    i++;
                if(s[i] == '*'){
                    valid=true;
                    operation = '*';
                    i++;
                }
                else if(s[i] == '/'){
                    valid=true;
                    operation = '/';
                    i++;
                }
                else if(s[i] == '+' || s[i] == '-'){
                    st.push(string(1,s[i]));
                    valid=false;
                    i++;
                }
            }
        }
        //now i was doing addition subtraction directly on the stack 
        //but i do that then evaluation would be right to left
        // For example 1-1+1 should ans as 1 and not -1
        //so i would everything in other stack so that everything from top to bottom is processed such a way that we are processing things left to right
        stack<string>st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        if(st2.size()>1){
            //top of st doesnt give us the ans so we perform the left operations of subtraction and addition and at end we get top of stack as our ans
            while(st2.size()>1){
                temp2=stoi(st2.top());
                st2.pop();
                if(st2.top() == string(1,'-')){
                    st2.pop();
                    temp1=stoi(st2.top());
                    st2.pop();
                    int ans=temp2-temp1;
                    st2.push(to_string(ans));
                }
                else if(st2.top() == string(1,'+')){
                    st2.pop();
                    temp1=stoi(st2.top());
                    st2.pop();
                    int ans=temp1+temp2;
                    st2.push(to_string(ans));
                }
            }
        }
        int res=stoi(st2.top());
        return res;
    }
};
// i thought of 2 stack idea and told chatgpt but it was rejected
//now concentrating on 1 stack idea, i got another idea to implement