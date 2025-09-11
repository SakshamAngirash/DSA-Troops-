#include<iostream> 
#include<stack>
using namespace std; 

void insertTemp(stack<int> &st,int temp)
{
    if(st.size()==0 || st.top()<temp)
    {
        st.push(temp); 
        return;
    }
    int val = st.top(); // store the last value; 
    st.pop(); 
    insertTemp(st,temp);
    st.push(val);  
}

void sortStack(stack<int> &st)
{
    if(st.size()==1)
    {
        return; // single element is already sorted 
    }

    int temp = st.top(); // remove the top element without loosing it 
    st.pop(); 
    sortStack(st); // sort the smaller stack 

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
    sortStack(st);
    while(st.size()>0)
    {
        cout<<st.top()<<" "; 
        st.pop();
    }
}