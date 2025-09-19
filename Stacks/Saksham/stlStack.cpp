#include<iostream> 
#include<stack>
using namespace std; 
int main ()
{
    stack<int> st; 
    st.push(10); 
    st.push(20); 
    st.push(30); 
    st.push(40); 
    st.push(50); 
    cout<<st.size()<<endl; 

    // printing all the elements of the stack 
    while(st.size()!=0){
        cout<<st.top()<<" "; 
        st.pop(); 
    }
    cout<<endl<<st.size()<<endl; // loose the elements 
    st.push(10); 
    st.push(20); 
    st.push(30); 
    st.push(40); 
    st.push(50); 
    
    // now print without loosing : we would need a temp stack 
    stack<int> temp; 
    while(st.size()!=0)
    {
        cout<<st.top()<<" "; 
        temp.push(st.top()); 
        st.pop(); 
    }
    // revert back temp to original stack 
    while(temp.size()!=0)
    {
        st.push(temp.top()); 
        temp.pop(); 
    }
    cout<<"temp size: "<<temp.size()<<endl; 


}