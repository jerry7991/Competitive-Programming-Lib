#include <iostream>

#include "TreeNode.h"
using namespace std;

string serialize(TreeNode* root) {
    string str = "";
    queue<TreeNode*> level;
    if (root) {
        level.push(root);
    }
    while (level.size()) {
        TreeNode* temp = level.front();
        level.pop();
        if (temp) {
            str.append(to_string(temp->val));
            level.push(temp->left);
            level.push(temp->right);
        } else {
            str.append("$");
        }
        str.append(",");
    }
    return str;
}

vector<string> split(string data, char cp) {
    vector<string> out;
    int i = 0, j = -1;
    while (i < data.size()) {
        if (data[i] == cp && i != j) {
            out.push_back(data.substr(j + 1, i - j - 1));
            j = i;
            i++;
        } else {
            i++;
        }
    }
    return out;
}

TreeNode* deserialize(string data) {
    vector<string> spt = split(data, ',');

    for (string str : spt) cout << str << " ";
    cout << endl;

    TreeNode* root = nullptr;
    queue<TreeNode*> level;
    if (spt.size() > 0 && spt[0] != "$") {
        root = new TreeNode(stoi(spt[0]));
        level.push(root);
    }
    int i = 1;
    while (level.size()) {
        TreeNode* temp = level.front();
        level.pop();
        string leftData = spt[i++];
        string rightData = spt[i++];
        if (leftData != "$") {
            temp->left = new TreeNode(stoi(leftData));
            level.push(temp->left);
        } else {
            temp->left = nullptr;
        }
        if (rightData != "$") {
            temp->right = new TreeNode(stoi(rightData));
            level.push(temp->right);
        } else {
            temp->right = nullptr;
        }
    }
    return root;
}

int main() {
    TreeNode* root = takeInput();
    string str = serialize(root);
    cout << "encrypted tree is :: " + str << endl;
    root = deserialize(str);
    cout << "Decrypted tree inorder is ::" << endl;
    printInOrder(root);
}