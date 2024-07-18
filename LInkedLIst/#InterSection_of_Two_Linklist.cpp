// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }

        ListNode* node1 = headA;
        ListNode* node2 = headB;

        while(node1 != node2){
            if(node1){
                node1 = node1->next;    // Why will it not cause infinite loop??
            }else{                     // Because after 2nd cycle both node1 and node2 will bacome NULL;
                node1 = headB;
            }

            if(node2){
                node2 = node2->next;
            }else{
                node2 = headA;
            }
        }


        return node1;
    }
};