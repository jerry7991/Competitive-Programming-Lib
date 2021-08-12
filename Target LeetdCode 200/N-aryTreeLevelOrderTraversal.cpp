class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> level;
        if (root) level.push(root);

        while (level.size()) {
            int n = level.size();
            vector<int> temp(n);
            while (--n >= 0) {
                Node *curr = level.front();
                level.pop();
                temp[n] = curr->val;
                for (Node * child : curr->children) {
                    if (child) level.push(child);
                }
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};