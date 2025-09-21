#include<iostream> 
using namespace std; 
class Queue{
    public: 
    int arr[5]; 
    int front = 0; // pop 
    int back = -1; // push 

    void push(int val)
    {
        if(back==4)
        {
            cout<<"Queue is full : overflow"<<endl;
            return; 
        }
        back++; 
        arr[back] = val; 
    }

    void pop()
    {
        if(front>back)
        {
            cout<<"Queue is empty : Underflow"<<endl; 
            return; 
        }
        front++; 
    }

    int top()
    {
        if(front>back)
        {
            cout<<"Queue is empty"<<endl; 
            return -1; 
        }
        return arr[front]; 

    }
    int size()
    {
        return back-front+1; 
    }

}; 

int main()
{
    Queue q; 

}