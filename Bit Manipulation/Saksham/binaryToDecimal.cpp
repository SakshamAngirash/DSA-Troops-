#include<iostream> 
#include<string> 
#include<algorithm>

using namespace std; 

long long myPow(long long x, long long n) {
    if(n==0) return 1; 
    if(n==1) return x; 
    
    if(n%2==0) {
        long long even = myPow(x,n/2); 
        return even*even; 
    } else {
        long long odd = myPow(x,n/2);
        return x*odd*odd; 
    }
}

int binary2Deci(string s)
{
    int len = s.size(); 
    int result = 0; 
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '1') { 
            result += myPow(2, (len - i - 1)); 
        }
    }
    return result; 
}

int main ()
{
    string s = "0101"; 
    cout << binary2Deci(s); 
}
