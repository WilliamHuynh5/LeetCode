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
        set<ListNode*> s;
        
        while (head) {
            if(!s.insert(head).second) {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};

/*
Poor method
    bool hasCycle(ListNode *head) {
        map<int, vector<ListNode*>> m;
        
        while (head) {
            if(m.count(head->val) && find(m[head->val].begin(), m[head->val].end(), head) != m[head->val].end()) {
                return true;
            } else {
                m[head->val].push_back(head);
            }
            head = head->next;
        }
        
        return false;
    }
*/