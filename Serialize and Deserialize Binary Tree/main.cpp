class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* f = q.front();
            q.pop();

            if (f != nullptr) {
                s += to_string(f->val) + ",";
                q.push(f->left);
                q.push(f->right);
            } else {
                s += ",";
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }

        stringstream ss(data);
        string temp;

        getline(ss, temp, ',');
        TreeNode* root = new TreeNode(stoi(temp));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();

            if (!getline(ss, temp, ',')) break;

            if (temp != "") {
                TreeNode* l = new TreeNode(stoi(temp));
                t->left = l;
                q.push(l);
            }

            if (!getline(ss, temp, ',')) break;

            if (temp != "") {
                TreeNode* r = new TreeNode(stoi(temp));
                t->right = r;
                q.push(r);
            }
        }

        return root;
    }
};
