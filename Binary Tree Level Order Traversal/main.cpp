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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result{};
        if (root == nullptr) return result;
        
        q.push(root);
        while(q.size() != 0){
            int s = q.size();
            vector<int> temp_result{};
            for (int i = 0 ; i < s ; i++){
                TreeNode* f = q.front();
                q.pop();
                temp_result.push_back(f->val);
                if (f->left != nullptr) q.push(f->left);
                if (f->right != nullptr) q.push(f->right);
            }
            result.push_back(temp_result);
        }

        return result;
    }
};

