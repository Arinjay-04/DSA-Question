// Remove Nth Node From End of List


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        int cnt = 0;
        int lim = count - n;
        cout<<lim;
        ListNode* dummy = new ListNode(0);
        dummy->next = head; 
        ListNode* node = head;
        ListNode* prev = dummy;
        while(node){
           if(cnt == count - n){
             prev->next = node->next;
             node = node->next;
             break;
             
           }else{
             prev = node;
             node = node->next;
             cnt++;
           }
        }
       
        head = dummy->next;
        return head;
    }
};