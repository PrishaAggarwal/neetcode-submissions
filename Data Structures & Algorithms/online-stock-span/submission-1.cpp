class StockSpanner {
private:
    stack<pair<int,int>>st;
    int span=1;

public:
    StockSpanner() {
        
    }

    int next(int price){
        span=1;
        if(st.empty()){
            st.push({price,span});
            return span;
        }
        while(!st.empty() && price>=st.top().first){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */