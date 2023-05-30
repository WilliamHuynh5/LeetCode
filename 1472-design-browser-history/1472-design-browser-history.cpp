#include <string>
typedef struct Node {
    string url;
    struct Node *next;
    struct Node *prev;
} Node;


class BrowserHistory {
    struct Node *head;
    struct Node *tail;
    struct Node *curr;
public:
    
    struct Node *construct_node(string url, Node *prev, Node *next) {
        struct Node *n = new Node;
        n->url = url;
        n->next = next;
        n->prev = prev;
        return n;
    }

    BrowserHistory(string homepage) {
        struct Node *n = construct_node(homepage, NULL, NULL);
        head = n;
        tail = n;
        curr = n;
    }
      
    void visit(string url) {
        struct Node *n = construct_node(url, curr, NULL);
        curr->next = n;
        curr = curr->next;
        tail = curr;
    }
    
    string back(int steps) {
        cout << "CURR:" << curr->url << "\n";
        for (int i = 0; i < steps; i++) {
            if (curr->prev == NULL) {
                return curr->url;
            }
            curr = curr->prev;
            cout << "BACK:" << curr->url << "\n";
        }
        return curr->url;
    }
    
    string forward(int steps) {
        cout << "CURR:" << curr->url << "\n";
        for (int i = 0; i < steps; i++) {
            if (curr->next == NULL) {
                return curr->url;
            }
            curr = curr->next;
            cout << "FORW:" << curr->url << "\n";
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