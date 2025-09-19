// pop heavy : O(n)
class MyStack {
public:
    queue<int> q; 
    int size; 
    MyStack() {
        size = 0; 
    }

    void push(int x) {
        q.push(x); // O(1)
        size++; 
    }
    
    int pop() {
        if(size==0) return -1; 
        for(int i=0; i<size-1; i++)
        {
            int x = q.front(); 
            q.pop();
            q.push(x); 
        }
        int ans = q.front(); 
        q.pop(); 
        size--; 
        return ans; 

    }
    
    int top() {
        if(size==0) return -1; 
        for(int i=0; i<size-1; i++)
        {
            int x = q.front();
            q.pop(); 
            q.push(x);
        }
        int ans = q.front(); 
        q.pop(); 
        q.push(ans); 
        return ans;     
    }
    
    bool empty() {
        if(size==0) return true; 
        else return false; 
        
    }
};