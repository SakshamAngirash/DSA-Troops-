class MyQueue {
public:
    stack<int> st; 
    stack<int> temp; 
     
    int size;
    MyQueue() {
        size = 0; 
    }
    
    void push(int x) {
        st.push(x); 
        size++; 
    }
    int pop() {
        if(size==0) return -1; //underflow 
        for(int i = 0; i<size-1; i++)
        {
            int x = st.top(); 
            st.pop(); 
            temp.push(x); 
        }
        int ans = st.top(); 
        st.pop(); 
        size--; 
        while(temp.size()!=0)
        {
            int x = temp.top(); 
            temp.pop(); 
            st.push(x); 
        }
        return ans; 
    }
    
    int peek() {
        if(size==0) return -1; //underflow 
        for(int i = 0; i<size-1; i++)
        {
            int x = st.top(); 
            st.pop(); 
            temp.push(x); 
        }
        int ans = st.top();  
        while(temp.size()!=0)
        {
            int x = temp.top(); 
            temp.pop(); 
            st.push(x); 
        }
        return ans; 
        
    }
    
    bool empty() {
        if(size==0) return true; 
        else return false; 
        
    }
};