// Given the head of a singly linked list, reverse the list, and return the reversed list.


ListNode* reverseList(ListNode* head) {
        ListNode* node1 = head;
        ListNode* node2 = head;
        ListNode* node3 = NULL;

        while(node1){
            node1 = node1->next;
            node2->next = node3;
            node3 = node2;
            node2 = node1;
        }

       return node3;             //////////////// THIS IS IMP ///////////////////////
                    //////i was returning node2 or node1 which would be NULL in this case/////////
    }