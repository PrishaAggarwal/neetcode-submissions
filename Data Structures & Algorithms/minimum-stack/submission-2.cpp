class MinStack {
private:
    stack<int>st;
    stack<int>st_min;
    int min=INT_MAX; //we have to check the most min value after inserting the value
public:
    //stack<int>st_min;
    //stack<int>st;
    //The above stack should be in private members 
    //if i make it private then the only method to modify this stack is using the functions i made
    //This is called encapsulation
    //Because the internal stack is an implementation detail. Users of the class should interact through the public API (push, pop, top, getMin) rather than modifying the underlying data structure directly.
    
    //Encapsulation means:
    //Hide the internal data of an object and allow access to it only through controlled functions (the public interface)
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty())
            min=value;
        st.push(value);
        if(min<value)
            st_min.push(min);
        else{
            min=value;
            st_min.push(value);
        }
    }
    
    void pop() {
        st.pop();
        st_min.pop();
        if(!st_min.empty())
            min=st_min.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }
};
