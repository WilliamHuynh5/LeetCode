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
    ListNode* reverseList(ListNode* head) {
        
        // If only one node in the linked list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Two pointers method
        // Keep track of the previous node and the current node
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        // Iterate through the linkedlist
        while (curr->next != nullptr) {
            
            // Create a temporary copy of curr->next,
            // as we need a way to increment curr
            ListNode *tempCurr = curr->next;
            
            // Set curr->next to the previous node
            // Hence reversing the order
            curr->next = prev;
            
            // Now the curr node points towards the prev node,
            // we can update the prev node to become the current node
            prev = curr;
            
            // Increment the curr using the tempCurr pointer we saved before
            curr = tempCurr;
        }
        
        // Set the next of the last node to point to the previous
        curr->next = prev;
        return curr;
    }
};