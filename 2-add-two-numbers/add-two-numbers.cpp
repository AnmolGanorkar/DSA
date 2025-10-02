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
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            insertAtTail(anshead, anstail, digit);
            carry = sum / 10;
        }

        return anshead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Directly add the numbers without reversing
        return add(l1, l2);
    }
};
