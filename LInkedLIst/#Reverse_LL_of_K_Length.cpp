



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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* node1 = head;
        int count = 0;
        while(node1){
           node1 = node1->next;
           count++;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode * prev = dummy;
        ListNode* node = head;
         int i=0;
         while(i+k <= count){
            ListNode* p = node;
            ListNode* curr = node;
            ListNode* q = NULL;
            for(int j=i; j<i+k; j++){
               node = node->next;
               p->next = q;
               q = p;
               p = node;
            }
            prev->next = q;
            curr->next = p;
            prev = curr;
            i = i+k;

         }

         return dummy->next;

    }
};