// INSERTION SORT : RECURSIVE O(N2)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; 
        ListNode* temp = sortList(head->next); 
        if(temp->val>head->val)
        {
            // insert at head 
            head->next = temp; 
            return head; 
        }
        ListNode* temp2 = temp; 
        bool biggest = true; 
        while(temp2->next!=NULL)
        {
            if(temp2->next->val>head->val)
            {
                // insert it here
                head->next = temp2->next; 
                temp2->next = head; 
                biggest=false; 
                break; 
            }
            temp2 = temp2->next; 
        }
        if(biggest==true){
            temp2->next = head; 
            head->next = NULL; 
        }
        return temp; 
    }
};


// MERGE SORT 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* c = new ListNode(100); 
        ListNode*temp = c; 
        while(a!=NULL && b!=NULL)
        {
            if(a->val<=b->val)
            {
                temp->next = a; 
                a=a->next; 
                temp=temp->next; 
            }
            else{
                temp->next = b; 
                b=b->next; 
                temp=temp->next; 
            }
        }
        if(a==NULL) temp->next = b; 
        else if(b==NULL) temp->next = a; 
        return c->next; 
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head; 
        ListNode* fast = head; 
        ListNode* slow = head; 
        while(fast->next!=NULL && fast->next->next!=NULL) // left middle
        {
            fast = fast->next->next; 
            slow = slow->next; 
        }
        ListNode* a = head; 
        ListNode* b = slow->next; 
        slow->next = NULL; // break the link
        a = sortList(a); 
        b = sortList(b); 
        ListNode* c = merge(a,b); 
        return c; 
        
    }
};