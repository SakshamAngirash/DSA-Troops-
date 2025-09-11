#include<iostream> 
#include<stack>
using namespace std; 

void deleteMiddle(stack<int> &st, int current, int mid)
{
    if(current==mid)
    {
        st.pop(); 
        return; 
    }
    int temp = st.top(); 
    st.pop(); 
    deleteMiddle(st,current+1,mid); 
    st.push(temp); 
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
    deleteMiddle(st,0,st.size()/2); 
    while(st.size()>0)
    {
        cout<<st.top()<<" "; 
        st.pop();
    }
}