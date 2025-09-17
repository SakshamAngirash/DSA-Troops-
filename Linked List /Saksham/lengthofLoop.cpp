class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head; 
        ListNode* fast = head; 
        bool hasCycle = false; 
        
        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; 
            fast = fast->next->next; 
            if (slow == fast) {
                hasCycle = true; 
                break; 
            }
        }

        if (!hasCycle) return 0; // no cycle

        // Step 2: Count cycle length
        int countCycles = 1; 
        fast = fast->next; 
        while (slow != fast) {
            fast = fast->next; 
            countCycles++;
        }

        return countCycles; 
    }
};
