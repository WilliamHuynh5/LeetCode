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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        auto i = 0;
        while (temp != NULL) {
            temp = temp->next;
            i++;
        }
        auto half = i/2;
        cout << half;
        
        for (auto j = 0; j < half; j++) {
            head = head->next;
        }
        return head;
    }
};