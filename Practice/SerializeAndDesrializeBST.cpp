#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string data = "";
		queue<TreeNode *>q;
		if (!root) return data;
		data += to_string(root->val);
		q.push(root);
		while (q.size()) {
			TreeNode *temp = q.front();
			q.pop();
			if (temp->left) {
				data += "," + to_string(temp->left->val);
				q.push(temp->left);
			} else {
				data += "," + to_string(-1);
			}
			if (temp->right) {
				data += "," + to_string(temp->right->val);
				q.push(temp->right);
			} else {
				data += "," + to_string(-1);
			}
		}
        return data;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.size() == 0) {
			return NULL;
		}
		int val = 0, i = 0;
		while (i < data.size() && data[i] != ',') {
			val = val * 10 + (data[i] - '0');
			i++;
		}
		TreeNode *root = new TreeNode(val);
		queue<TreeNode *> q;
		q.push(root);
		while (q.size()) {
			TreeNode *temp = q.front();
			q.pop();
			for (val = -2, i += 1; i < data.size() && data[i] != ','; i++) {
				val = (val == -2 ) ? 0 : val;
				val = val * 10 + (data[i] - '0');
			}
			if (val >= 0) {
				temp->left = new TreeNode(val);
				q.push(temp->left);
			}
			for (val = -2, i += 1; i < data.size() && data[i] != ','; i++) {
				val = (val == -2) ? 0 : val;
				val = val * 10 + (data[i] - '0');
			}
			if (val >= 0) {
				temp->right = new TreeNode(val);
				q.push(temp->right);
			}
		}
		return root;
	}
};

TreeNode *takeInput() {
	int data; cin >> data;
	if (data == -1) return NULL;
	TreeNode *root = new TreeNode(data);
	queue<TreeNode*> q;
	q.push(root);
	while (q.size()) {
		TreeNode *temp = q.front();
		q.pop();
		cin >> data;
		if (data != -1) {
			temp->left = new TreeNode(data);
			q.push(temp->left);
		}
		cin >> data;
		if (data != -1) {
			temp->right = new TreeNode(data);
			q.push(temp->right);
		}
	}
	return root;
}
void inorder(TreeNode *root) {
	if (!root)return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}
int main() {

	TreeNode *root = takeInput();
	inorder(root);
	cout << '\n';
	Codec* ser = new Codec();
	Codec* deser = new Codec();
	string tree = ser->serialize(root);
	TreeNode* ans = deser->deserialize(tree);
	inorder(ans);
	return 0;
}