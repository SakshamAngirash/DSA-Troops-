#include<iostream> 
#include<queue> 
using namespace std; 

class Stack{
    public: 
    queue<int> q; 
    int size = 0; 

    void push(int val)
    {
        q.push(val); 
        size++; 
    }
    void pop()
    {
        if(size == 0 ) return; //underflow
        for(int i = 0; i<size-1 ; i++)
        {
            int x = q.front(); 
            q.pop(); 
            q.push(x);
        }
        q.pop();
        size--;  
    }
    int top()
    {
        if(size == 0 ) return -1; //underflow
        for(int i = 0; i<size-1 ; i++)
        {
            int x = q.front(); 
            q.pop(); 
            q.push(x);
        }
        int ans = q.front(); 
        q.pop(); 
        q.push(ans); // put it back
        return ans;   
    }

}; 
int main ()
{

}