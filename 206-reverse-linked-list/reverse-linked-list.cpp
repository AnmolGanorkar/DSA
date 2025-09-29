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
    // it will return head of the reverse list
    ListNode* reverse1(ListNode* head){

        //base case
        if (head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* smallerHead =  reverse1(head->next);
        head -> next -> next = head;
        head->next=NULL;

        return smallerHead;

    }

    void reverse(ListNode* &head , ListNode* curr , ListNode* prev){

        if(curr==NULL){
            head =  prev;
            return;
        }

        ListNode* forward = curr -> next;
        reverse(head ,  forward, curr);
        curr -> next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        //recursive appoarch -2
        return reverse1(head);


        /*
        //recursive appoarch -1
        ListNode *prev = NULL;
        ListNode *curr = head;
        reverse(head , curr , prev);
        return head;
        */
        /*

        //interative method
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        while(curr!=NULL){
            forward = curr -> next; 
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        */
    }
};