/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head) return nullptr;
        Node* curr = head;
        map<Node*, Node*> mp{};
        while(curr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        for(auto& [key,val]:mp){
            val->next = mp[key->next];
            val->random = mp[key->random]; 
        }

        return mp[head];
        
    }
};
