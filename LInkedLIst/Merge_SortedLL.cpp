// 21. Merge Two Sorted Lists
// Solved
// Easy
// Topics
// Companies
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.



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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* node = head;

        while(list1 && list2){
             if(list1->val < list2->val){
                node->next = new ListNode(list1->val);
                list1 = list1->next;
             }
             else{
                node->next = new ListNode(list2->val);
                list2 = list2->next;
             }

             node = node->next;
        }

        if(list1){
            node->next = list1;
        }
        if(list2){
            node->next = list2;
            
        }

        return head->next;
    }
};