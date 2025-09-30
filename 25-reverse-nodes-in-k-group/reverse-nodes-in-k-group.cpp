class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        // Step 1: check if there are at least k nodes left
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) return head; // not enough nodes, leave as is

        // Step 2: reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: recurse on the rest of the list
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // Step 4: return new head (prev is the head after reversing k nodes)
        return prev;
    }
};
