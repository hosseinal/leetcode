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
        
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* copyOfL1 = l1;

        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val;

            if (sum >= 10) {
                int rightVal = sum % 10;   // current digit
                int leftVal  = sum / 10;   // carry to next node

                l1->val = rightVal;

                if (l1->next != nullptr) {
                    l1->next->val += leftVal;
                } else {
                    l1->next = new ListNode(leftVal);
                }
            } else {
                l1->val = sum;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2 != nullptr) {
            ListNode* tail = copyOfL1;
            while (tail->next != nullptr){
                tail = tail->next;
            }
            tail->next = l2;
        }

        ListNode* node = copyOfL1;
        while (node != nullptr){
            if (node->val >= 10 ){

                int leftOver = node->val / 10;
                node->val = node->val %10;
                if (node->next != nullptr) {
                    node->next->val += leftOver;
                } else {
                    node->next = new ListNode(leftOver);
                }

            }
            node = node->next;
        }

        
        return copyOfL1;
    }
};

