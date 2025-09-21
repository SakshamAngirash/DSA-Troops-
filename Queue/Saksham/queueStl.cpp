#include<iostream> 
#include<queue> 
using namespace std; 
// lets do this pass by reference
void display(queue<int> &q)
{
    int n = q.size(); 
    for(int i = 0; i<n; i++)
    {
        int x = q.front(); 
        cout<<q.front<<" "; 
        q.pop(); 
        q.push(x); 
    }
    cout<<endl;
    
}

int main ()
{
    queue<int> q; 
    q.push(10); 
    q.push(20); 
    cout<<q.size(); 
    display()

}