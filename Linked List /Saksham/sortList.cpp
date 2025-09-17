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