#include<iostream>
#include<string> 
#include<algorithm>
using namespace std; 

string convert2Binary(int n)
{
    string result = ""; 
    while(n!=0)
    {
        if(n%2==0) result+='0'; // add to the front incase want to avoid the reverse
        else result+='1'; 
        n=n/2; 
    }
    reverse(result.begin(),result.end());
    return result; 
}

int main ()
{
    int n = 3; // decimals 
    cout<<convert2Binary(n)<<endl; 
}