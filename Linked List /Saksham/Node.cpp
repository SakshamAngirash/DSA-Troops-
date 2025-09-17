#include<iostream> 
using namespace std; 


class Node{
    public: 
    int val; 
    Node* next; 
    Node* prev; 
    Node(int val)
    {
        this->val = val; 
        this->next = NULL; 
        this ->prev = NULL; 
    }
}; 

