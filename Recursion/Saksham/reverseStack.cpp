#include<iostream> 
#include<stack>
using namespace std; 

void insertTemp(stack<int>&st, int temp)
{
    // base case : if stack is empty then push the temp 
    if(st.size()==0) 
    {
        st.push(temp); 
        return; 
    }
    int val = st.top(); 
    st.pop(); 
    insertTemp(st, temp); 
    st.push(val); 

}


void reverseStack(stack<int> &st)
{
    if(st.size()<=1)
    {
        // stack is already reverse 
        return; 
    }
    int temp = st.top(); 
    st.pop();
    reverseStack(st); 
    insertTemp(st,temp); 
    
}

int main ()
{
    stack<int> st; 
    st.push(10); 
    st.push(20); 
    st.push(5);
    st.push(1); 
    st.push(2); 
    st.push(50);
    cout<<st.size()<<endl;
    reverseStack(st); 
    reverseStack(st); 
    while(st.size()>0)
    {
        cout<<st.top()<<" "; 
        st.pop();
    }
}