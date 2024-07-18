        ListNode* node1= head;
        ListNode* temp= new ListNode();
        ListNode* node2 = temp;
        temp->next = head;

        while(node1){
            if(store[node1->val] != 0){
                node2->next = node1->next;
                delete node1;
                node1= node2 ->next;
            }
            else{
                node2 = node1;
                node1 = node1->next;
            }
        }

        head = temp->next;
        delete temp