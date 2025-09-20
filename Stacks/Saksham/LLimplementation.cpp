#include<iostream> 
using namespace std; 

class Node{
    public:
    int val; 
    Node* next; 
    Node(int val)
    {
        this->val = val; 
        this->next = NULL; 
    }

}; 

class Stack{
    public: 
    Node* head; 
    int size; 
    Stack()
    {
        head=NULL; 
        size = 0; 
    }
    void push(int val)
    {
        Node* temp = new Node(val); 
        if(head==NULL)
        {
            head = temp; 
            size++; 
            return; 
        }
        temp->next = head; 
        head = temp ; 
        size++; 
        return; 
    }
    void pop()
    {
        if(head == NULL )
        {
            cout<<"Cant pop:underflow"; 
            return; 
        }
        head = head->next; 
        size--; 

    }
    int top()
    {
        if(head == NULL)
        {
            cout<<"stack is empty"; 
            return; 
        }
        return head->val; 
    }
}; 