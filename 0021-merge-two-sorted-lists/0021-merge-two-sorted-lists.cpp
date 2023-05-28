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
        
        ListNode res = ListNode();
        ListNode *temp = &res;
        
        while (list1 && list2) {
            
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        // cout << temp->val << "\n";
        // cout << list1->val << "\n";
        // cout << list2->val << "\n";
        if (list1 == nullptr) {
            temp->next = list2;
        } else if (list2 == nullptr) {
            temp->next = list1;
        }
        
        return res.next;
    }
};