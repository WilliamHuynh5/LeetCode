#include <string>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int> v1;
        while (l1 != NULL) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        vector<int> v2;
        while (l2 != NULL) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        
        auto carry = 0;
        
        auto iter = (v1.size() > v2.size()) ? v1.size() : v2.size();
        vector<int> resVec;
        
        for (auto i = 0; i < iter; i++) {
            
            if (i >= v1.size()) {
                auto sum = v2.at(i) + carry;
                resVec.push_back(sum % 10);
                carry = (sum >= 10) ? 1 : 0;  
            } else if (i >= v2.size()){
                auto sum = v1.at(i) + carry;
                resVec.push_back(sum % 10);
                carry = (sum >= 10) ? 1 : 0;  
            } else {
                auto sum = v1.at(i) + v2.at(i) + carry;
                resVec.push_back(sum % 10);
                carry = (sum >= 10) ? 1 : 0;    
            }
        }
        if (carry > 0) {
           resVec.push_back(carry); 
        }
            
        
        for (auto elem : resVec){
            cout << elem;
        }
        
        auto res = new ListNode;
        reverse(resVec.begin(), resVec.end());
        
        for (auto i = 0; i < resVec.size(); i++){
            if (i == 0) {
                res->val = resVec[i];
                res->next = NULL;
            } else {
                auto newNode = new ListNode;
                newNode->val = resVec[i];
                newNode->next = res;
                res = newNode;      
            }

        }
        
        return res;
    }
    
};