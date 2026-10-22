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

class Codec {
   public:
    string serialize(TreeNode* root) {
        vector<string> tree;
        serializeHelper(root, tree);
        return join(tree, ",");
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> elements = split(data, ',');
        int index = 0;
        return deserializeHelper(elements, index);
    }

   private:
    void serializeHelper(TreeNode* node, vector<string>& tree) {
        if (!node) {
            tree.push_back("N");
            return;
        }

        tree.push_back(to_string(node->val));
        serializeHelper(node->left, tree);
        serializeHelper(node->right, tree);
    }

    TreeNode* deserializeHelper(const vector<string>& elements, int& index) {
        if (elements[index] == "N") {
            ++index;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(elements[index]));
        ++index;

        node->left = deserializeHelper(elements, index);
        node->right = deserializeHelper(elements, index);
        return node;
    }

    string join(const vector<string>& values, const string& delimiter) {
        ostringstream out;
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) out << delimiter;
            out << values[i];
        }
        return out.str();
    }

    vector<string> split(const string& text, char delimiter) {
        vector<string> elements;
        stringstream stream(text);
        string item;

        while (getline(stream, item, delimiter)) {
            elements.push_back(item);
        }

        return elements;
    }
};
