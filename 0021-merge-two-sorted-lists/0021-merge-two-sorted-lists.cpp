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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Create a new List
        ListNode res = ListNode();
        // Pointer to that new list
        ListNode *temp = &res;
        
        // Iterate through both list1 and list2
        while (list1 && list2) {
            
            // If list1 node is less than list2 node, 
            // insert it into the temp list
            // move the list1 pointer next
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } 
            // Otherwise, insert the list2 node into the temp list
            // move the list2 pointer next
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temp list pointer next
            temp = temp->next;
        }
        
        // There will be leftover elements in one of the lists
        // Since those elements are already sorted,
        // simply append whichever list is not NULLPTR at the end of temp list
        if (list1 == nullptr) {
            temp->next = list2;
        } else if (list2 == nullptr) {
            temp->next = list1;
        }
        
        // Return the list
        return res.next;
    }
};