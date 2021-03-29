#include<iostream>
#include <unordered_map>
using namespace std;
#include "TreeNode.h"
int rob(TreeNode<int> *root) {
	if (!root) {
		return 0;
	}
	//	For storing the tree
	vector<int> tree;

	//	Make a graph
	unordered_map<int, vector<int> > graph;

	//	For level order traversal
	queue<TreeNode<int> *> qNode;

	//	For storing index
	queue<int> qIndex;

	//	Append root
	qNode.push(root);

	//	Storing the index
	int index = -1;

	//	Store index as well
	qIndex.push(-1);

	//	traveral untill qNode become empty
	while (qNode.size()) {

		//	Get the front from queue
		TreeNode<int> * temp = qNode.front();
		qNode.pop();

		//	Get the parent index
		int pIndex = qIndex.front();
		qIndex.pop();

		//	If the temp exist
		if (temp) {

			//	Increment the index
			index++;
			tree.push_back(temp->val);
			graph[pIndex].push_back(index);

			// Store
			qNode.push(temp->left);
			qIndex.push(index);
			qNode.push(temp->right);
			qIndex.push(index);
		}
	}
	//	Make dp for robbed and notRobbed
	int *robbed = new int[index + 1]();
	int *notRobbed = new int[index + 1]();

	//	From leafe
	for (int i = index ; i >= 0; i--) {
		vector<int> edge = graph[i];
		if (edge.size() == 0) {
			//	If it is leafe
			robbed[i] = tree[i];
			notRobbed[i] = 0;
		} else {
			robbed[i] = tree[i];
			for (auto child : edge) {
				robbed[i] += notRobbed[child];
				notRobbed[i] += max(robbed[child] , notRobbed[child]);
			}
		}

	}
	return max(robbed[0] , notRobbed[0]);
}
int main() {
	TreeNode<int> *root = takeInput();
	cout << rob(root) << endl;
}