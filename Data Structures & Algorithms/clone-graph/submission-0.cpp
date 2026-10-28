/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        // this also acts as the visited counter

        function<Node*(Node*)> dfs = [&](Node* node) -> Node* {
            if (node == nullptr) return nullptr;

            // check if visited
            if (oldToNew.contains(node)) return oldToNew[node];

            // make a new node
            // populate neighbors

            Node* newCopy = new Node(node->val);
            oldToNew[node] = newCopy;
            for (auto nei : node->neighbors) {
                newCopy->neighbors.push_back(dfs(nei));
            }

            return newCopy;
        };

        return dfs(node);
    }
};
