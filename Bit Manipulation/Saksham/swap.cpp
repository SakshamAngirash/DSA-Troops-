class Solution {
public:
    void swap(int &a, int &b) {
        a = a^b; 
        b = a^b;
        a = a^b;
        // Your code goes here
    }
}