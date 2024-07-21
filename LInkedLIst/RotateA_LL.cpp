
// 61. Rotate List
// Medium


// Given the head of a linked list, rotate the list to the right by k places.



// 1)) BRUTE FORCE

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        while(k >0){
            ListNode* curr = head;
            ListNode* node = head;   //This gave TLE because of larger value of K;
            ListNode* prev = NULL;

            while(curr->next){
                prev = curr;
               curr = curr->next;
               
            }
            curr -> next = node;
            prev->next = NULL;
            head = curr;
            k--;
        }
        return head;
    }
};


// Better APproach 


/// TIME COMPLEXITY OF O(N x K);

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        
        k = k%count;                   // Reducing k to k%count
        while(k >0){                //ALWAYS REMEMBER TO REDUCE THE K TO SMALLEST POSSIBLE VALUE BY TAKING MODULAR WITH LENGTH
            ListNode* curr = head;
            ListNode* node = head;
            ListNode* prev = NULL;

            while(curr->next){
                prev = curr;
               curr = curr->next;
               
            }
            curr -> next = node;
            prev->next = NULL;
            head = curr;
            k--;
        }
        return head;
    }
};



// MOST OPTIMISED APPROACH

/// TIME COMPLEXITY O(N);


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp = head;

        int count = 0;

        while(temp->next){
            temp = temp->next;
            count++;
        }
        cout<<count<<endl;
        count += 1;


        temp ->next = head;
        temp = head;              // Make a circular LL

        int newlenght = count - (k%count) - 1;
        cout<<newlenght<<endl;
        ListNode* node = temp->next;
        while(newlenght >0){
            temp = node;
            node = node->next;
            newlenght--;
        }

        cout<<temp->val;

        temp->next = NULL;

        return node;
    }
};


