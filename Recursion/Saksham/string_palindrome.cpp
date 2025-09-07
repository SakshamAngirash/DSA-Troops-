#include<iostream>
#include<string> 
using namespace std; 

bool palindrome(string &str, int ptr)
{
    if(ptr>str.size()/2) return true; 
    if(str[ptr]!=str[str.length()-ptr-1]) return false; 
    return palindrome(str,ptr+1);

}
int main ()

{
    string s = "madams"; 
    int len = s.length(); 
    cout<<palindrome(s,0);

}

// leetcode solution 
class Solution {
public:
    bool checkPalindrome(string& str, int ptr) {
        if (ptr >= str.size() / 2) return true;
        if (str[ptr] != str[str.size() - ptr - 1]) return false;
        return checkPalindrome(str, ptr + 1);
    }

    bool isPalindrome(string s) {
        // we need to remove the non-alphanumeric things
        // we need to consider caps and smalls as same
        string cleaned;
        for (char c : s) {
            if (isalnum(c)) cleaned += tolower(c);
        }
        return checkPalindrome(cleaned, 0);
    }
};

bool isAlnum(char c) {
    return (c >= '0' && c <= '9') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= 'a' && c <= 'z');
}
