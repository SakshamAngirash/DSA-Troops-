/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0 ; 
        int lenB = 0 ; 
        ListNode* temp = headA; 
        // calculate the length of both 
        while(temp!=NULL)
        {
            temp=temp->next; 
            lenA++; 
        }

        temp = headB; 
        while(temp!=NULL)
        {
            temp=temp->next; 
            lenB++; 
        }
        
        // Align the heads 

        if(lenA>lenB)
        {
            while(lenA!=lenB)
            {
                lenA--; 
                headA=headA->next; 
            }
        }
        else{
            while(lenB!=lenA)
            {
                lenB--; 
                headB=headB->next; 
            }
        }

        // Calculate the intersection point 
        while(headA!=headB)
        {
            headA= headA->next; 
            headB=headB->next; 
        }
        return headA;


        
    }
};