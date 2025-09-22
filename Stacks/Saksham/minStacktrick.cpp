class MinStack {
public:
    stack<long long> st;   // use long long to avoid overflow
    long long min;         // current minimum
    
    MinStack() {
        min = LLONG_MAX;   // initially infinity
    }

    void push(int val) {
        long long x = val; 
        if(st.size()==0)
        {
            // if the stack is empty 
            min = x; 
            st.push(x); 
        }
        else if(x<min)
        {
            // fake entry (encoded value)
            st.push(2*x-min);
            min = x; 
        }
        else if(x>=min) st.push(x);         
    }
    
    void pop() {
        if(st.size()==0) return; // underflow
        if(st.top()<min)
        {
            // fake value -> restore old min
            min = 2*min - st.top(); 
            st.pop(); 
        }
        else st.pop(); 
    }
    
    int top() {
        if(st.size()==0) return -1; // underflow
        else if(st.top()<min)
        {
            // if fake entry -> actual top is current min
            return (int)min; 
        }
        else return (int)st.top(); 
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
