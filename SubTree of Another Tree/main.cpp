/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool isEqual(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        return isEqual(root->left, subRoot->left) &&
               isEqual(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (root==nullptr || subRoot == nullptr) return false;
        //find subroot
        int val = subRoot->val;
        TreeNode* targetPointer = nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0){
            TreeNode* t = q.front();
            q.pop();
            if(t == nullptr) continue;
            
            if(t->val == subRoot->val){
                targetPointer = t;
                bool r = isEqual(targetPointer, subRoot);
                if (r) return true;
            }
            q.push(t->left);
            q.push(t->right);
            

        }
        
        return false;

    }
};

