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

class Queue{
    public:
    Node* head ;
    int size; 
    Queue()
    {
        size = 0; 
        head = NULL; 
    }
    void push (int val)
    {
        Node* temp = new Node(val); 
        if(head==NULL)
        {
            head = temp;
            size++;  
            return; 
        }
        Node* t = head; 
        while(t->next!=NULL)
        {
            t=t->next; 
        }
        t->next = temp; 
        size++; 
    }
    void pop()
    {
        if(size==0){
            cout<<"empty : underflow"<<endl; 
            return; 
        }
        head = head->next; 
        size--; 
    }
    int front()
    {
        if(size ==0) return -1; 
        return head->val; 
    }

}; 