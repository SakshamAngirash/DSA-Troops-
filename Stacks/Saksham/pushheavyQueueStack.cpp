class MyStack {
public:
    queue<int> q; 
    int size; 
    MyStack() {
        size = 0; 
        
    }
    
    void push(int x) {
        q.push(x); 
        size++; 
        for(int i = 0; i<size-1; i++)
        {
            int temp = q.front(); 
            q.pop(); 
            q.push(temp); 
        }
        
    }
    
    int pop() {
        if(size==0) return -1; 
        int ans = q.front(); 
        q.pop(); 
        size--; 
        return ans; 
    }
    
    int top() {
        if(size==0) return -1; 
        return q.front(); 
    }
    
    bool empty() {
        if(size==0) return true; 
        else return false; 
        
    }
};