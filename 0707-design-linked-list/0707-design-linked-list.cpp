#include <cstdlib>
typedef struct Node {
    int val;
    Node *next;
} Node;

class MyLinkedList {
    Node *head;
    Node *tail;
    int size;
public:
    MyLinkedList() {
        struct Node* n = new Node;
        head = n;
        tail = n;
        size = 0;
    }
    
    int get(int index) {
        if (index  < 0 || index >= size) {
            return -1;
        } 
        
        struct Node* curr = head;
        for (auto i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        struct Node* n = new Node;
        n->val = val;
        
        n->next = head;
        if (size == 1) {
            tail = head;
        }
        head = n;
        size++;
    }
    
    void addAtTail(int val) {
        struct Node* n = new Node;
        n->val = val; 
        
        if(size == 0) {
            head = n;
        }
        
        tail->next = n;
        tail = tail->next;
        if (size == 1) {
            head->next = tail;
        }
        size++;

    }
    
    void addAtIndex(int index, int val) {
        if (index  < 0 || index > size) {
            return;
        } else if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {    
            struct Node* n = new Node;
            n->val = val;

            struct Node* curr = head;
            for (auto i = 0; i < index - 1;  i++) {
                curr = curr->next;
            }
            struct Node* temp = curr->next;
            curr->next = n;
            n->next = temp;  
            size++;    
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        } else if (index == 0) {
            head = head->next;
            size--;
        } else if (index == size - 1) {
            struct Node* curr = head;
            for (auto i = 0; i < index - 1;  i++) {
                curr = curr->next;
            }
            curr->next = NULL;
            tail = curr;
            size--;
        } else {
            struct Node* curr = head;
            for (auto i = 0; i < index - 1;  i++) {
                curr = curr->next;
            }
            curr->next = curr->next->next;
            size--;
        }
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