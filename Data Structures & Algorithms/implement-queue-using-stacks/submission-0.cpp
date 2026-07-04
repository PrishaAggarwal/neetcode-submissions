class MyQueue {
private:
    stack<int>s1;
    stack<int>s2;
public:
    MyQueue() {
        //its a constructor so nothing here
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int b=s2.top();
            s2.pop();
            return b;
        }
        else{
            while(!s1.empty()){
                int a=s1.top();
                s1.pop();
                s2.push(a);
            }
            int c=s2.top();
            s2.pop();
            return c;
        }
        return -1;
    }
    
    int peek() {
        if(!s2.empty()){
            int b=s2.top();
            return b;
        }
        else{
            while(!s1.empty()){
                int a=s1.top();
                s1.pop();
                s2.push(a);
            }
            int c=s2.top();
            return c;
        }
        return -1;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */