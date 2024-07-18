// Add Two Numbers
// Solved
// Medium
// Topics
// Companies
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode(0);
        ListNode* head = node;
        int carry = 0;
        while(l1 && l2){
            int value = l1->val+l2->val +carry;
            if(value >= 10){
                carry = 1;
                node->next = new ListNode(value - 10);
            }else{
                carry = 0;
                node->next = new ListNode(value );
            }
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int value = l1->val +carry;
            if(value >= 10){
                node->next = new ListNode(value - 10);
                carry = 1;
            }else{
                node->next = new ListNode(value);
                carry = 0;
            }
            node = node->next;
            l1 = l1->next;
        }
        while(l2){
            int value = l2->val +carry;
            if(value >= 10){
                node->next = new ListNode(value - 10);
                carry = 1;
            }else{
                node->next = new ListNode(value);
                carry = 0;
            }
            node = node->next;
            l2 = l2->next;
        }

        if(carry == 1){
            node ->next = new ListNode(carry);
        }

        return head->next;
    }
};

        ///////// OR ///////////////////////////////////

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int c = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = c + l1->val + l2->val;
            if (sum > 9) {
                c = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
            } else {
                c = 0;
                head->next = new ListNode(sum);
                head = head->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = c + l1->val;
            if (sum > 9) {
                c = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
            } else {
                c = 0;
                head->next = new ListNode(sum);
                head = head->next;
            }
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = c + l2->val;
            if (sum > 9) {
                c = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
            } else {
                c = 0;
                head->next = new ListNode(sum);
                head = head->next;
            }
            l2 = l2->next;
        }
        if (c > 0) {
            head->next = new ListNode(c);
            head = head->next;
        }
        head->next = NULL;
        return temp->next;
    }
};