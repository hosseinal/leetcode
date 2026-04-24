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
        if (head == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> pairs;

        Node* headC = head;
        while (headC != nullptr) {
            pairs[headC] = new Node(headC->val);
            headC = headC->next;
        }

        Node* headNC = head;
        while (headNC != nullptr) {
            Node* newNode = pairs[headNC];
            newNode->next = pairs[headNC->next];
            newNode->random = pairs[headNC->random];
            headNC = headNC->next;
        }

        return pairs[head];
    }
};

