bool has_cycle(Node* head) {
                if(head == NULL){
                        return false;
                }
                Node *tmp1 = head;
                Node *tmp2;
                for(int i = 0; i<=100; i++){
                        tmp2 = tmp1->next;
                        for(int j = 0; j<=101;j++){
                                if(tmp2 == NULL){
                                        return false;
                                }
                                if(tmp2 == tmp1){
                                        return true;
                                }
                                tmp2 = tmp2->next;
                        }
                        tmp1 = tmp1->next;
                }
                return false;
        }

