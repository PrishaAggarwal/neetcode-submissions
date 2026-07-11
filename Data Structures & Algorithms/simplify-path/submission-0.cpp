class Solution {
public:
    string simplifyPath(string path) {
        stack<string>directory;
        string temp;
        string res;
        for(char c:path){
            if( c!= '/'){
                temp += c;
            }
            else{
                if(temp == string(1,'.')){
                    temp.clear();
                }
                else if(temp == string(2,'.')){
                    //string(2,'.') means ..
                    if(!directory.empty()){
                        directory.pop();
                        temp.clear();
                    } 
                    temp.clear(); //by chance directory is empty and we have nothing to pop but then also hum temp khali krenge
                }
                else{
                    if(!temp.empty()){
                        //if condition kyuki agar by chance temp is empty then empty string would be pushed to stack
                        directory.push(temp);
                        temp.clear();
                    }
                }
            }
        }
        if(!temp.empty() && temp != string(1,'.') && temp != string(2,'.')){
            //agar last mein bracket nhi hoa then end mein temp mein jo hoga voh stack mein jayega hi nhi kyuki temp wala goes to stack only when bracket comes
            //so special case for that
            // by chance end mein .. ya . hoa in temp and we are already in root directory then these dots would be added faltu mein
            directory.push(temp);
        }
        if(!temp.empty() && temp == string(2,'.') && !directory.empty()){
            directory.pop();
            //end wala by chance .. hoa and we are in middle someehre then pop toh krna hoga na
        }
        if(directory.empty()){
            res='/';
            return res;
        }
        while(!directory.empty()){
            //res += '/';
            //i want to append the top of directory to start of string so instead of writing what i wrote down, i would write....
            //res += directory.top();
            res = '/' + directory.top() + res;
            directory.pop();
        }
        return res;
    }
};