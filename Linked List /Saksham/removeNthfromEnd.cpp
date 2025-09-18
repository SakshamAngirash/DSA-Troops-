class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL; 
        if(head->next == NULL) return NULL; 
        ListNode* slow = head; 
        ListNode* fast = head; 
        for(int i=0;i<n;i++)
        {
            fast=fast->next; 
        }
        if (fast == NULL) {
            return head->next;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next; 
            fast = fast->next; 
        }
        slow->next = slow->next->next; 
        return head; 
        
    }
};