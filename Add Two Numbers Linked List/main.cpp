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

    int sum(ListNode* l1, ListNode* l2, int carry){
        int res = 0;
        if(l1) res+=l1->val;
        if(l2) res+=l2->val;

        return res+carry;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        int s = 0;
        int carry = 0;
        ListNode* root= new ListNode(s);
        ListNode* node = root;
        while(l1 != nullptr && l2 != nullptr){
            int s = sum(l1,l2,carry);
            if (s >= 10){
            carry = 1;
            s = s - 10;
            }else{
                carry = 0;
            }
            ListNode* n = new ListNode(s);
            root->next= n;
            root= root->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            s = sum(l1,nullptr,carry);
            if (s >= 10){
            carry = 1;
            s = s - 10;
            }else{
                carry = 0;
            }
            ListNode* n = new ListNode(s);
            root->next= n;
            root= root->next;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            s = sum(l2,nullptr,carry);
            if (s >= 10){
            carry = 1;
            s = s - 10;
            }else{
                carry = 0;
            }
            ListNode* n = new ListNode(s);
            root->next= n;
            root= root->next;
            l2 = l2->next;
        }

        if(carry){
            ListNode* n = new ListNode(carry);
            root->next = n;
        }



        return node->next;
    }
};
