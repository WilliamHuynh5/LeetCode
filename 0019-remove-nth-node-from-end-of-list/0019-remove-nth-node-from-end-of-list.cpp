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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = head;
        ListNode *current = head->next;
        
        auto size = getSize(head);
        auto toIter = (size - n);
        
        if (size == 1) {
            head = NULL;
            return head;
        }
        if (toIter == 0){
            head = head->next;
            return head;
        }
        
        for (auto i = 0; i < toIter; i++){
            if (i == (toIter - 1)) {
                prev->next = current->next;
                current->next = NULL;
                break;
            } 
            prev = prev->next;
            current = current->next;
        }
        
        return head;
    }
    
    int getSize(ListNode* head) {
        if (head == NULL) {
            return 0;
        }
        return 1 + getSize(head->next);
    }
};