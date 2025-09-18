
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head; 
        ListNode* zeroHead = new ListNode(-1); 
        ListNode* oneHead = new ListNode(-1); 
        ListNode* twoHead = new ListNode(-1); // dummy nodes 

        ListNode* zero = zeroHead; // this is for traversal 
        ListNode* one = oneHead; 
        ListNode* two = twoHead; 

        // using temp to iterate over ListNode head 
        ListNode* temp = head; 

        while(temp!=NULL)
        {
            if(temp->val==0)
            {
                zero->next = temp; 
                zero = zero->next; 
            }
            else if(temp->val == 1)
            {
                one->next = temp; 
                one = one->next; 
            }
            else {
                // temp->val == 2
                two->next = temp; 
                two = two->next; 

            }
            temp = temp->next; 
            
        }
        zero->next = oneHead->next ? oneHead->next : twoHead->next; 
        one->next = twoHead->next; 
        two->next = NULL; 
        // link the nodes 
        return zeroHead->next; 


    }
};