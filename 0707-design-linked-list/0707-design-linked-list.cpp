#include <cstdlib>

// Struct for a Node
typedef struct Node {
    int val;
    Node *next;
} Node;

class MyLinkedList {
    // Singly linked list
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
        // If out of bounds, return -1
        if (index  < 0 || index >= size) {
            return -1;
        } 
    
        // Create a current node and traverse to the index
        struct Node* curr = head;
        for (auto i = 0; i < index; i++) {
            curr = curr->next;
        }
        // Return value of node at index
        return curr->val;
    }
    
    void addAtHead(int val) {
        // Create a new node
        struct Node* n = new Node;
        n->val = val;
        
        // Since, n will be the new head,
        // make n's next point to the old head
        n->next = head;
        // If size is 1, then the new tail will be the old head
        if (size == 1) {
            tail = head;
        }
        // Make the new head point to n
        head = n;
        size++;
    }
    
    void addAtTail(int val) {
        // Create a new node
        struct Node* n = new Node;
        n->val = val; 
        
        // If size is 0, then the new head will be n
        if(size == 0) {
            head = n;
        }
        // Since inserting at tail,
        // simply make the tail->next point to the new node
        tail->next = n;
        
        // Increment the tail to the new node
        tail = tail->next;
        
        // If size of list was 1, make the head->next point to the new tail
        if (size == 1) {
            head->next = tail;
        }
        size++;

    }
    
    void addAtIndex(int index, int val) {
        // If out of bounds, return 
        if (index  < 0 || index > size) {
            return;
        } 
        // If index is 0, add at head
        else if (index == 0) {
            addAtHead(val);
        } 
        // If index is size, add at tail
        else if (index == size) {
            addAtTail(val);
        } 
        // Else, traverse to the index and insert
        else {    
            struct Node* n = new Node;
            n->val = val;
            
            // Traverse to the index
            struct Node* curr = head;
            for (auto i = 0; i < index - 1;  i++) {
                curr = curr->next;
            }
            
            // Keep a temp pointer to the next node
            struct Node* temp = curr->next;
            // Set the next pointer of the current node to the new node
            curr->next = n;
            // Set the next pointer of the new node to the temp pointer
            n->next = temp;  
            size++;    
        }
    }
    
    void deleteAtIndex(int index) {
        // If out of bounds, return
        if (index < 0 || index >= size) {
            return;
        } 
        // If index is 0, simply increment the head
        else if (index == 0) {
            head = head->next;
            size--;
        } 
        // If index is size - 1, make the tail point to the tail's previous node
        else if (index == size - 1) {
            struct Node* curr = head;
            // Traverse to the node before the tail
            for (auto i = 0; i < index - 1;  i++) {
                curr = curr->next;
            }
            // Set the next pointer of the node before the tail to NULL
            curr->next = NULL;
            tail = curr;
            size--;
        } 
        // Else, traverse to the index and delete
        else {
            struct Node* curr = head;
            // Traverse to the node before the index
            for (auto i = 0; i < index - 1;  i++) {
                curr = curr->next;
            }
            // Set the next pointer of the node before the index to the node after the index
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