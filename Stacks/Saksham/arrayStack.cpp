#include<iostream> 
using namespace std; 
class Stack { 
    public: 
    int arr[5]; 
    int idx = -1; 

    void push(int val)
    {
        if(idx==4)
        {
            cout<<"stack is full"; 
            return; 
        }
        idx++;  
        arr[idx]=val; 
    }

    void pop()
    {
        if(idx == -1){
            cout<<"UnderFlow : No more elements to pop";
            return; 
        }
        idx--; 

    }

    int top()
    {
        if(idx==-1)
        {
            cout<<"Stack is empty"; 
            return -1; 
        }
        return arr[idx]; 
    }

    int size(){
        return idx+1; 
    }
    void display(){
        if(idx+1==0){
            cout<<"Nothing to display"<<endl; 
            return; 
        }
        for(int i=0; i<idx+1; i++)
        {
            cout<<arr[i]<<" "; 
        }
    }


};
int main ()
{
    Stack st; 
    st.push(10); 
    st.push(20); 
    st.push(30); 
    st.push(40); 
    st.push(50); 
    st.display();
    // st.push(60); stack might be full 
    

}