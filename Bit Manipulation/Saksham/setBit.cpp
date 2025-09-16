#include<iostream> 
using namespace std; 

int setBit(int value, int idx)
{
    return value | (1<<idx);
}

int main ()
{
    int val = 9 ; 
    cout<<setBit(val,2); 
}