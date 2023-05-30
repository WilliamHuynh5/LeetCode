#include <string>
// Struct for a doubly linked node
// Has a field for the url (string),
// As well as a next and prev pointer
typedef struct Node {
    string url;
    struct Node *next;
    struct Node *prev;
} Node;

// BrowserHistory class
// Has a head and tail pointer
// As well as a pointer to keep track of the current page
class BrowserHistory {
    struct Node *head;
    struct Node *tail;
    struct Node *curr;
public:
    
    // Helper function to create a node
    struct Node *construct_node(string url, Node *prev, Node *next) {
        struct Node *n = new Node;
        n->url = url;
        n->next = next;
        n->prev = prev;
        return n;
    }
    
    // Construct a browser history from a homepage
    // Since there is only one homepage/url to start,
    // The head, tail, and curr points to the same node
    BrowserHistory(string homepage) {
        struct Node *n = construct_node(homepage, NULL, NULL);
        head = n;
        tail = n;
        curr = n;
    }
    
    // Create a new node, and insert it after the current position
    void visit(string url) {
        // The prev of `n` will be `curr`, 
        // since we are inserting `n` after `curr`
        struct Node *n = construct_node(url, curr, NULL);
        
        // Set the next of `curr` to `n`,
        // since we are inserting after `curr`
        curr->next = n;
        
        // Increment the `curr` pointer, as we have just
        // inserted a new node, and it is now our new `curr`
        curr = curr->next;
        // Update the `tail` to be the `curr`
        tail = curr;
    }
    
    string back(int steps) {
        // Traverse back in the LL `steps` times
        for (int i = 0; i < steps; i++) {
            if (curr->prev == NULL) {
                return curr->url;
            }
            curr = curr->prev;
        }
        return curr->url;
    }
    
    // Traverse forward in the LL `steps` times
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->next == NULL) {
                return curr->url;
            }
            curr = curr->next;
        }
        return curr->url;    
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */