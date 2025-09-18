class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        if (head == NULL) return NULL;

        // Step 1: remove leading target nodes
        while (head != NULL && head->val == target) {
            ListNode* toDelete = head;
            head = head->next;
            if (head != NULL) head->prev = NULL;
            // delete toDelete; // optional cleanup
        }

        // Step 2: traverse and delete in-between target nodes
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == target) {
                ListNode* toDelete = temp->next;
                temp->next = toDelete->next;
                if (toDelete->next != NULL) {
                    toDelete->next->prev = temp;
                }
                // delete toDelete; // optional cleanup
                // don't move temp forward
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
