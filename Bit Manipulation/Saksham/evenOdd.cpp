#include<iostream> 
using namespace std; 

void checkEO(int x)
{
    if((x & 1) == 1) cout<<"Odd"; 
    else cout<<"Even";
}


int main ()
{
    checkEO(7); 
}