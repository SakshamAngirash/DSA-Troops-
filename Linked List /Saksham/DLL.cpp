#include<iostream>
using namespace std; 

class Node{
    public:
    int val ; 
    Node* prev ;
    Node* next; 
    Node(int val)
    {
        this->val=val; 
        this->prev=NULL; 
        this->next=NULL; 
    }
}; 
class DLL{
    public:
    Node* head; 
    Node* tail; 
    int size; 
    DLL(){
        head=tail=NULL; 
        size=0;
    }
    //insertion 
    void insertAtTail(int val)
    {
        Node* temp = new Node(val); 
        if(size==0)head=tail=temp; 
        else{
            tail->next=temp; 
            temp->prev=tail; //extra
            tail=temp; 
        }
        size++; 
    }
    void insertAthead(int val)
    {
        Node* temp = new Node(val); 
        if(size==0)head=tail=temp; 
        else{
            temp->next=head; 
            head->prev=temp; //extra 
            head=temp; 
        }
        size++; 
    }
    void insertAtIdx(int val,int idx)
    {
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl; 
        else if(idx==0) insertAthead(val); 
        else if(idx==size) insertAtTail(val); 
        else{
            Node* t=new Node(val); 
            Node* temp = head;  
            for (int i = 1; i <= idx-1; i++)
            {
                temp=temp->next; 
            }
            t->next = temp->next;
            temp->next=t; 
            t->prev= temp; 
            t->next->prev = t; 
            size++;    
        }
    }


    //deletion 
    void deleteAtHead()
    {
        if(size==0 || head==NULL) {
            cout<<"List is empty"<<endl; 
            return; 
            }
        else {
            head->next->prev=NULL; 
            head = head->next;
            size--;
        }    
    }
    void deleteAtTail()
    {
        if(size==0){
        cout<<"List is Empty"<<endl; 
        return ; 
        }
        else if(size==1) deleteAtHead(); 
        else{
            Node* temp = tail->prev; 
            temp->next=NULL;
            tail=temp;
        }
    }
    void deleteAtIdx(int idx)
    {
        if(size==0){
            cout<<"List is empty"<<endl;
            return ;
        }
        else if(size==1 || idx==1) deleteAtHead(); 
        else if(idx==size-1)deleteAtTail(); 
        else{
            Node* temp=head;
            for (int i = 1; i <= idx-1; i++)
            {
                temp=temp->next; 
            }
            temp->next=temp->next->next;
            temp->next->prev=temp; 
            size--;
            
        }
    }

    //get function 
    int getAtIdx(int idx)
    {
        if(idx<0||idx>=size)
        {
            cout<<"Invalid Index";
        }
        else if(idx==0)return head->val; 
        else if(idx=size-1)return tail->val; 
        else{
            Node* temp = head; 
            for (int i = 1; i <= idx; i++)
            {
                temp=temp->next;
            }
            return temp->val;
            //we can also optimise this as we already knwo the size
        }
    }

    //display function 
    void display(){
        Node* temp = head; 
        while(temp)
        {
            cout<<temp->val<<"-->>";
            temp= temp->next; 

        }
        cout<<endl;
    }
};
int main()
{
    DLL sample; 
    sample.insertAthead(10); 
    sample.insertAtTail(20); 
    sample.insertAthead(5); 
    sample.insertAthead(6);
    sample.display();
    sample.insertAtIdx(2,2); 
    sample.display();
    sample.deleteAtHead();
    sample.display();
    DLL sample2; 
    sample2.deleteAtHead();
    sample.deleteAtIdx(2);
    sample.display();