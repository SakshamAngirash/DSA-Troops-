/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return head; 
        ListNode* curr = head; 
        ListNode* prev = NULL; 
        ListNode* front = NULL; 
        while(curr!=NULL)
        {
            front = curr->next; 
            curr ->next = prev; 
            prev = curr; 
            curr = front; 
        }
        return prev; 
    }
    ListNode *addOne(ListNode *head) {
        ListNode* newHead = reverseList(head); 
        int carry  = 1 ; // borrow can here be only 0 and 1 
        
        ListNode* temp = newHead; 
        while(temp!=NULL && carry>0)
        {
            int sum = temp->val + carry; 
            temp->val = sum%10; 
            carry = sum / 10; 

            // move ahead

            // if it is the last 
            if(temp->next == NULL && carry>0)
            {
                // add a new node 
                temp->next = new ListNode(carry); 
                carry = 0; 
            }
            temp = temp->next; 
        }
        return reverseList(newHead); 

        


    }
};
