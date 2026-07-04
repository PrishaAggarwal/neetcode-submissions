class MyStack {
private:
    queue<int>q1; //for storing elements of stack where front of queue is bottom of stack
    //so back of queue is top of stack
    queue<int>q2;
    //so whenever we wanna pop we would push all elements to other queue untill only one element is left, and we would pop it from front 
    //we would push into queue that is non empty
public:
    MyStack() {
        //just a constructor here
    }
    
    void push(int x) {
        if(!q1.empty())
            q1.push(x);
        else if(q1.empty() && q2.empty())
            q1.push(x);
        else 
            q2.push(x);
    }
    
    int pop() {
        if(q2.empty()){
            while(q1.size()>1){
                int a=q1.front();
                q1.pop();
                q2.push(a);
            }
            int res=q1.front();
            q1.pop();
            return res;
        }
        else{
            while(q2.size()>1){
                int a=q2.front();
                q2.pop();
                q1.push(a);
            }
            int res=q2.front();
            q2.pop();
            return res;
        }
    }
    
    int top(){
        if(!q1.empty())
            return q1.back();
        else if(!q2.empty())
            return q2.back();
        else
            return -1;
    }
    
    //thought of optimization myself
    /*
    int top() {
        if(q2.empty()){
            while(q1.size()>1){
                int a=q1.front();
                q1.pop();
                q2.push(a);
            }
            int res=q1.front();
            q1.pop();
            q2.push(res);
            return res;
        }
        else{
            while(q2.size()>1){
                int a=q2.front();
                q2.pop();
                q1.push(a);
            }
            int res=q2.front();
            q2.pop();
            q1.push(res);
            return res;
        }
    }
    */

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */