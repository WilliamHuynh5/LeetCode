/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Use Floyd's tortoise and hare algorithm
        // It is a cycle-finding algorithm that uses two pointers,
        // a slow pointer (tortoise) and a fast pointer (hare)
        // the slow pointer is incremented by 1 position
        // the fast pointer is incremented by 2 positions
        
        // If there is NO CYCLE, the fast pointer will encounter `nullptr`, and hence can return false
        // If there is A CYCLE, the fast pointer and the slow pointer
        // will eventually intersect, and once they do, we can return true
        
        // Time Complexity: O(n)
        // Space Complexity: O(1)
        
        
        // If list is null return false
        if  (head == nullptr) {
            return false;
        }
        
        // Initialise the slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        
        // If there is a cycle, this while loop 
        // will continuously run
        while (fast->next && fast->next->next) {
            // Increment the two pointers.
            slow = slow->next;
            fast = fast->next->next;
            
            // If there is an intersection, return true
            if (slow == fast) {
                return true;
            }
        }
        // If there is no cycle, the loop will
        // eventually terminate and hence return false.
        return false;
    }
};

/*
Poor method which uses hashset
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        
        while (head) {
            if(!s.insert(head).second) {
                return true;
            }
            head = head->next;
        }
        return false;
    }
*/