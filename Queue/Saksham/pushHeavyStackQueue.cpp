class MyQueue {
public:
    stack<int> st;   
    stack<int> temp;
    int size;

    MyQueue() {
        size = 0;
    }

    void push(int x) {
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        size++;
    }

    int pop() {
        if(size == 0) return -1; // underflow
        int ans = st.top();
        st.pop();
        size--;
        return ans;
    }

    int peek() {
        if(size == 0) return -1; //underflow
        return st.top();
    }

    bool empty() {
        return size == 0;
    }
};
