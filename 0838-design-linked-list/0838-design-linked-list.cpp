class MyLinkedList {
public:
    ListNode*head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size=0;
        
    }
    
 int get(int index) {
    if (index < 0 || index >= size) return -1;
    ListNode* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}

void addAtHead(int val) {
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node;
    size++;
}

void addAtTail(int val) {
    ListNode* node = new ListNode(val);
    if (!head) {
        head = node;
    } else {
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
    size++;
}

void addAtIndex(int index, int val) {
    if (index < 0 || index > size) return; 
    if (index == 0) {
        addAtHead(val);
        return;
    }
    if (index == size) {
        addAtTail(val);
        return;
    }
    ListNode* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    ListNode* node = new ListNode(val);
    node->next = temp->next;
    temp->next = node;
    size++;
}

void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return; 
    if (index == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    } else {
        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
    }
    size--;
}

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */