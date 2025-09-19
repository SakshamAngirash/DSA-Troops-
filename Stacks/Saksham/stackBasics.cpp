#include<iostream> 
#include<stack> 
using namespace std; 

void display(stack<int> st)
{
    // since via pass by value we wont need a new stack 
    while(st.size()!=0)
    {
        cout<<st.top()<<" "; 
        st.pop(); 
    }
    cout<<endl; 
}

void displayRec(stack<int> st)
{
    if(st.size()==0) return; 
    cout<<st.top()<<" "; 
    st.pop(); 
    displayRec(st); 
}
int main()
{
    stack<int>st; 
    st.push(10); 
    st.push(20); 
    st.push(30); 
    st.push(40); 
    st.push(50);
    
    display(st); 
    display(st); 

    displayRec(st);
    cout<<endl;  
    displayRec(st); 
    


}